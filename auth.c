#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.h"

#if defined(_WIN32) || defined(_WIN64)
#define strcasecmp _stricmp
#endif

int adminLogin() {
    char username[30], password[30];
    int attempts = 0;

    while (attempts < MAX_LOGIN_ATTEMPTS) {
        printf("\n--- Admin Login ---\n");
        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        if (strcmp(username, ADMIN_USERNAME) == 0 &&
            strcmp(password, ADMIN_PASSWORD) == 0) {
            printf("\nLogin successful! Welcome, Admin.\n");
            return 1;
        } else {
            attempts++;
            printf("Incorrect username or password. Attempts left: %d\n",
                   MAX_LOGIN_ATTEMPTS - attempts);
        }
    }
    return 0;
}

void addGame() {
    FILE *file = fopen("games.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Game g;
    printf("Enter Game Name: ");
    fgets(g.name, sizeof(g.name), stdin);
    g.name[strcspn(g.name, "\n")] = '\0';

    printf("Enter Price Per Hour: ");
    while (scanf("%lf", &g.price) != 1) {
        printf("Invalid price! Try again: ");
        while (getchar() != '\n');
    }

    printf("Enter Duration (in minutes): ");
    while (scanf("%d", &g.duration) != 1) {
        printf("Invalid duration! Try again: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    fprintf(file, "%s\n%.2lf\n%d\n", g.name, g.price, g.duration);
    fclose(file);
    printf("Game feature '%s' added successfully!\n", g.name);
}

void deleteGame() {
    char targetGame[30];
    printf("Enter Game Name to delete: ");
    fgets(targetGame, sizeof(targetGame), stdin);
    targetGame[strcspn(targetGame, "\n")] = '\0';

    FILE *file = fopen("games.txt", "r");
    if (!file) {
        printf("No custom games configured yet.\n");
        return;
    }
    FILE *tempFile = fopen("temp_games.txt", "w");
    if (!tempFile) {
        fclose(file);
        printf("Error creating temporary file.\n");
        return;
    }

    struct Game g;
    char buffer[50];
    int deleted = 0;

    while (fgets(g.name, sizeof(g.name), file) != NULL) {
        g.name[strcspn(g.name, "\n")] = '\0';
        if (fgets(buffer, sizeof(buffer), file)) g.price    = atof(buffer);
        if (fgets(buffer, sizeof(buffer), file)) g.duration = atoi(buffer);

        if (strcasecmp(g.name, targetGame) == 0 && !deleted) {
            deleted = 1;
            continue;
        }
        fprintf(tempFile, "%s\n%.2lf\n%d\n", g.name, g.price, g.duration);
    }
    fclose(file);
    fclose(tempFile);

    remove("games.txt");
    rename("temp_games.txt", "games.txt");

    if (deleted)
        printf("Game feature '%s' has been successfully removed from the system.\n", targetGame);
    else
        printf("No game named '%s' was found to delete.\n", targetGame);
}

void viewGames() {
    FILE *file = fopen("games.txt", "r");
    if (!file) {
        printf("\n⚠️  No custom games configured yet by management.\n");
        return;
    }

    char buffer1[50], buffer2[50];
    struct Game g;
    printf("\n--- Available Games & Rates ---\n");

    while (fgets(g.name, sizeof(g.name), file) != NULL) {
        g.name[strcspn(g.name, "\n")] = '\0';

        if (!fgets(buffer1, sizeof(buffer1), file)) break;
        g.price = atof(buffer1);

        if (!fgets(buffer2, sizeof(buffer2), file)) break;
        g.duration = atoi(buffer2);

        if (strlen(g.name) > 0)
            printf("- %s ($%.2lf/Hour)\n", g.name, g.price);
    }
    printf("--------------------------------\n");
    fclose(file);
}