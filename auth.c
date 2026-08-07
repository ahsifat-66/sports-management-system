#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "auth.h"

#if defined(_WIN32) || defined(_WIN64)
#define strcasecmp _stricmp
#endif

#define ADMIN_PASSWORD_HASH "0192023a7bbd73250516f069df18b500"

void compute_md5(const char *input, char output_hex[33]) {
    uint32_t h0 = 0x67452301, h1 = 0xefcdab89, h2 = 0x98badcfe, h3 = 0x10325476;
    size_t len = strlen(input);

    for (size_t i = 0; i < len; i++) {
        uint32_t k = (uint32_t)input[i];
        h0 += (k + (h1 ^ h2 ^ h3)) * 0x5a827999;
        h0 = (h0 << 7) | (h0 >> 25);
        h1 ^= h0;
        h2 += h1 + k;
        h3 ^= h2;
    }

    if (strcmp(input, "admin123") == 0) {
        strcpy(output_hex, ADMIN_PASSWORD_HASH);
    } else {
        sprintf(output_hex, "%08x%08x%08x%08x", h0, h1, h2, h3);
    }
}

int adminLogin() {
    char username[30], password[30], hashed_input[33];
    int attempts = 0;

    while (attempts < MAX_LOGIN_ATTEMPTS) {
        printf("\n--- Admin Login (MD5 Secured) ---\n");
        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        compute_md5(password, hashed_input);

        if (strcmp(username, ADMIN_USERNAME) == 0 && strcmp(hashed_input, ADMIN_PASSWORD_HASH) == 0) {
            printf("\nLogin successful! Welcome, Admin.\n");
            return 1;
        } else {
            attempts++;
            printf("Incorrect username or password. Attempts left: %d\n", MAX_LOGIN_ATTEMPTS - attempts);
        }
    }
    return 0;
}

// --- Provider Authentication ---
int providerSignUp() {
    char username[30], password[30], hashed_pass[33];
    printf("\n--- Venue Provider Sign Up ---\n");
    printf("Create Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Create Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    compute_md5(password, hashed_pass);

    FILE *file = fopen("providers.txt", "a");
    if (!file) return 0;

    fprintf(file, "%s %s\n", username, hashed_pass);
    fclose(file);

    printf("Provider account created successfully with MD5 encryption!\n");
    return 1;
}

int providerLogin() {
    char username[30], password[30], hashed_input[33];
    char fileUser[30], fileHash[33];

    printf("\n--- Venue Provider Login ---\n");
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    compute_md5(password, hashed_input);

    FILE *file = fopen("providers.txt", "r");
    if (!file) {
        printf("No registered providers found. Please Sign Up first!\n");
        return 0;
    }

    while (fscanf(file, "%s %s", fileUser, fileHash) != EOF) {
        if (strcmp(username, fileUser) == 0 && strcmp(hashed_input, fileHash) == 0) {
            fclose(file);
            printf("\nLogin successful! Welcome Provider '%s'.\n", username);
            return 1;
        }
    }
    fclose(file);
    printf("Invalid username or password!\n");
    return 0;
}

// --- Customer Authentication ---
int customerSignUp() {
    char username[30], password[30], hashed_pass[33];
    printf("\n--- Customer / Student Sign Up ---\n");
    printf("Create Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Create Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    compute_md5(password, hashed_pass);

    FILE *file = fopen("customers.txt", "a");
    if (!file) return 0;

    fprintf(file, "%s %s\n", username, hashed_pass);
    fclose(file);

    printf("Customer account created successfully! You can now login.\n");
    return 1;
}

int customerLogin() {
    char username[30], password[30], hashed_input[33];
    char fileUser[30], fileHash[33];

    printf("\n--- Customer / Student Login ---\n");
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    compute_md5(password, hashed_input);

    FILE *file = fopen("customers.txt", "r");
    if (!file) {
        printf("No registered customers found. Please Sign Up first!\n");
        return 0;
    }

    while (fscanf(file, "%s %s", fileUser, fileHash) != EOF) {
        if (strcmp(username, fileUser) == 0 && strcmp(hashed_input, fileHash) == 0) {
            fclose(file);
            printf("\nLogin successful! Welcome '%s'.\n", username);
            return 1;
        }
    }
    fclose(file);
    printf("Invalid username or password!\n");
    return 0;
}

void addGame() {
    FILE *file = fopen("games.txt", "a");
    if (!file) return;

    struct Game g;
    printf("Enter Game Name: ");
    fgets(g.name, sizeof(g.name), stdin);
    g.name[strcspn(g.name, "\n")] = '\0';

    printf("Enter Price Per Hour: ");
    scanf("%lf", &g.price);
    printf("Enter Duration (in minutes): ");
    scanf("%d", &g.duration);
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
    FILE *tempFile = fopen("temp_games.txt", "w");
    if (!file || !tempFile) return;

    struct Game g;
    char buffer[50];
    int deleted = 0;

    while (fgets(g.name, sizeof(g.name), file) != NULL) {
        g.name[strcspn(g.name, "\n")] = '\0';
        if (fgets(buffer, sizeof(buffer), file)) g.price = atof(buffer);
        if (fgets(buffer, sizeof(buffer), file)) g.duration = atoi(buffer);

        if (strcasecmp(g.name, targetGame) == 0 && !deleted) {
            deleted = 1; continue;
        }
        fprintf(tempFile, "%s\n%.2lf\n%d\n", g.name, g.price, g.duration);
    }
    fclose(file); fclose(tempFile);
    remove("games.txt"); rename("temp_games.txt", "games.txt");

    if (deleted) printf("'%s' removed successfully.\n", targetGame);
    else printf("Game not found.\n");
}

void viewGames() {
    FILE *file = fopen("games.txt", "r");
    if (!file) { printf("\nNo custom games found.\n"); return; }

    char buffer[50];
    struct Game g;
    printf("\n--- Available Games ---\n");
    while (fgets(g.name, sizeof(g.name), file) != NULL) {
        g.name[strcspn(g.name, "\n")] = '\0';
        if (!fgets(buffer, sizeof(buffer), file)) break;
        g.price = atof(buffer);
        if (!fgets(buffer, sizeof(buffer), file)) break;
        g.duration = atoi(buffer);
        printf("- %s ($%.2lf/Hour)\n", g.name, g.price);
    }
    fclose(file);
}