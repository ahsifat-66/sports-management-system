#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "schedule.h"
#include "booking.h"

void viewSchedule() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) {
        printf("\nNo bookings scheduled yet. Everything is open!\n");
        return;
    }

    struct Booking b;
    char buffer[50];
    printf("\n--- Current Complex Schedule ---\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        b.bookingId = atoi(buffer);

        if (!fgets(b.customerName, sizeof(b.customerName), file)) break;
        b.customerName[strcspn(b.customerName, "\n")] = '\0';

        if (!fgets(b.gameName, sizeof(b.gameName), file)) break;
        b.gameName[strcspn(b.gameName, "\n")] = '\0';

        if (!fgets(b.timeSlot, sizeof(b.timeSlot), file)) break;
        b.timeSlot[strcspn(b.timeSlot, "\n")] = '\0';

        if (!fgets(buffer, sizeof(buffer), file)) break;
        b.hours = atoi(buffer);

        if (!fgets(buffer, sizeof(buffer), file)) break;
        b.totalBill = atof(buffer);

        printf("ID: #%05d | Slot: [%s] | Game: %s | Booked By: %s | Total: $%.2lf\n",
               b.bookingId, b.timeSlot, b.gameName, b.customerName, b.totalBill);
    }
    fclose(file);
}

void viewMembers() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) {
        printf("\nNo one has booked/confirmed anything yet.\n");
        return;
    }

    struct Booking b;
    char buffer[50];
    int count = 0;

    printf("\n--- Members Who Confirmed a Booking ---\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        b.bookingId = atoi(buffer);

        if (!fgets(b.customerName, sizeof(b.customerName), file)) break;
        b.customerName[strcspn(b.customerName, "\n")] = '\0';

        if (!fgets(b.gameName, sizeof(b.gameName), file)) break;
        b.gameName[strcspn(b.gameName, "\n")] = '\0';

        if (!fgets(b.timeSlot, sizeof(b.timeSlot), file)) break;
        b.timeSlot[strcspn(b.timeSlot, "\n")] = '\0';

        if (!fgets(buffer, sizeof(buffer), file)) break;
        b.hours = atoi(buffer);

        if (!fgets(buffer, sizeof(buffer), file)) break;
        b.totalBill = atof(buffer);

        count++;
        printf("%d. %s  (Game: %s, Slot: %s, Booking ID: #%05d)\n",
               count, b.customerName, b.gameName, b.timeSlot, b.bookingId);
    }
    fclose(file);

    if (count == 0) printf("No confirmed members found.\n");
    printf("----------------------------------------\n");
    printf("Total Confirmed Members: %d\n", count);
}

void cancelbooking() {
    int targetId;
    printf("Enter Booking ID to cancel: ");
    if (scanf("%d", &targetId) != 1) {
        printf("Invalid ID format.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    FILE *file = fopen("bookings.txt", "r");
    if (!file) {
        printf("No bookings data found.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        fclose(file);
        printf("Error creating temporary file.\n");
        return;
    }

    struct Booking b;
    char buffer[50];
    int deleted = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        b.bookingId = atoi(buffer);

        if (!fgets(b.customerName, sizeof(b.customerName), file)) break;
        b.customerName[strcspn(b.customerName, "\n")] = '\0';

        if (!fgets(b.gameName, sizeof(b.gameName), file)) break;
        b.gameName[strcspn(b.gameName, "\n")] = '\0';

        if (!fgets(b.timeSlot, sizeof(b.timeSlot), file)) break;
        b.timeSlot[strcspn(b.timeSlot, "\n")] = '\0';

        if (!fgets(buffer, sizeof(buffer), file)) break;
        b.hours = atoi(buffer);

        if (!fgets(buffer, sizeof(buffer), file)) break;
        b.totalBill = atof(buffer);

        if (b.bookingId == targetId && !deleted) {
            deleted = 1;
            continue;
        }
        fprintf(tempFile, "%d\n%s\n%s\n%s\n%d\n%.2lf\n",
                b.bookingId, b.customerName, b.gameName,
                b.timeSlot, b.hours, b.totalBill);
    }
    fclose(file);
    fclose(tempFile);

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (deleted)
        printf("Booking #%05d has been canceled successfully.\n", targetId);
    else
        printf("No matching Booking ID found.\n");
}

void viewNoticeBoard() {
    FILE *file = fopen("notice.txt", "r");
    printf("\n==================================================\n");
    printf("     📢 COMPLEX NOTICE BOARD & REGULATIONS       \n");
    printf("==================================================\n");

    if (!file) {
        printf(" 1. Non-marking sports shoes are strictly required.\n");
        printf(" 2. Please arrive 10 minutes prior to your slot.\n");
        printf(" 3. Cancellations must be made via Booking ID.\n");
        printf(" 4. Equipment damage charges apply to offenders.\n");
        printf(" 5. Respect staff and fellow players at all times.\n");
        printf("==================================================\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    printf("==================================================\n");
    fclose(file);
}

void updateNoticeBoard() {
    FILE *file = fopen("notice.txt", "w");
    if (!file) {
        printf("Error writing notice board.\n");
        return;
    }

    char noticeText[200];
    printf("Enter new announcement for the Notice Board:\n> ");
    fgets(noticeText, sizeof(noticeText), stdin);

    fprintf(file, "📢 ANNOUNCEMENT: %s", noticeText);
    fprintf(file, "\n--- STANDARD COMPLEX RULES ---\n");
    fprintf(file, "1. Non-marking shoes required on court.\n");
    fprintf(file, "2. Arrive 10 minutes before slot start time.\n");
    fprintf(file, "3. Maintain sportsmanship and safety.\n");

    fclose(file);
    printf("✅ Notice board updated successfully!\n");
}