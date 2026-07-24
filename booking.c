#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "booking.h"
#include "auth.h"

#if defined(_WIN32) || defined(_WIN64)
#define strcasecmp _stricmp
#endif

int doesGameExist(char *game) {
    FILE *file = fopen("games.txt", "r");
    if (!file) return 0;

    struct Game g;
    char buffer[50];

    while (fgets(g.name, sizeof(g.name), file) != NULL) {
        g.name[strcspn(g.name, "\n")] = '\0';
        if (!fgets(buffer, sizeof(buffer), file)) break;
        if (!fgets(buffer, sizeof(buffer), file)) break;

        if (strcasecmp(g.name, game) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

double getGamePrice(char *game) {
    FILE *file = fopen("games.txt", "r");
    if (!file) return 15.0;

    struct Game g;
    char buffer[50];

    while (fgets(g.name, sizeof(g.name), file) != NULL) {
        g.name[strcspn(g.name, "\n")] = '\0';

        if (fgets(buffer, sizeof(buffer), file))
            g.price = atof(buffer);
        else
            g.price = 15.0;

        if (!fgets(buffer, sizeof(buffer), file)) break;

        if (strcasecmp(g.name, game) == 0) {
            fclose(file);
            return g.price;
        }
    }
    fclose(file);
    return 15.0;
}

void bookGame(int isAdmin) {
    struct Booking b;
    int startHour, endHour;

    viewGames();

    printf("Enter Game Name from the list above to book: ");
    fgets(b.gameName, sizeof(b.gameName), stdin);
    b.gameName[strcspn(b.gameName, "\n")] = '\0';

    if (!doesGameExist(b.gameName)) {
        printf("\nERROR: '%s' is not an available sport! Booking rejected.\n", b.gameName);
        return;
    }

    printf("Enter Start Hour (24-hour format, e.g., 9 or 14): ");
    if (scanf("%d", &startHour) != 1) {
        printf("\nERROR: Please enter a single integer number only!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    printf("Enter End Hour (24-hour format, e.g., 12 or 17): ");
    if (scanf("%d", &endHour) != 1) {
        printf("\nERROR: Please enter a single integer number only!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (endHour <= startHour || startHour < 0 || endHour > 24) {
        printf("\nERROR: Invalid time parameters entered!\n");
        return;
    }

    b.hours = endHour - startHour;
    sprintf(b.timeSlot, "%02d:00 - %02d:00", startHour, endHour);

    if (isAdmin) printf("Enter Customer Name (Manual Walk-in): ");
    else         printf("Enter Your Name: ");
    fgets(b.customerName, sizeof(b.customerName), stdin);
    b.customerName[strcspn(b.customerName, "\n")] = '\0';

    b.bookingId = (int)(time(NULL) % 100000);

    double basePrice = getGamePrice(b.gameName);
    b.totalBill = basePrice * b.hours;

    FILE *file = fopen("bookings.txt", "a");
    if (!file) {
        printf("Error writing to bookings database!\n");
        return;
    }
    fprintf(file, "%d\n%s\n%s\n%s\n%d\n%.2lf\n",
            b.bookingId, b.customerName, b.gameName,
            b.timeSlot, b.hours, b.totalBill);
    fclose(file);

    printf("\n✅ Booking confirmed successfully!\n");
    printf("Generated Booking ID : #%05d\n", b.bookingId);
    printf("Calculated Duration  : %d Hour(s) (Slot: %s)\n", b.hours, b.timeSlot);
    printf("Total Cost           : $%.2lf ($%.2lf/hr x %d hours)\n",
           b.totalBill, basePrice, b.hours);
}