#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "booking.h"

// Display already booked slots for a specific venue on a chosen date
void showBookedSlots(const char* venueName, const char* date) {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) return;

    char line[200];
    int found = 0;

    printf("\n--- Booked Slots for '%s' on %s ---\n", venueName, date);

    while (fgets(line, sizeof(line), file)) {
        int bId;
        char cust[50], ven[50], dt[15], slt[20];
        double prc;

        if (sscanf(line, "%d,%49[^,],%49[^,],%14[^,],%19[^,],%lf", &bId, cust, ven, dt, slt, &prc) == 6) {
            if (strcasecmp(ven, venueName) == 0 && strcmp(dt, date) == 0) {
                printf("  [Occupied] Time: %-18s | Booked By: %s\n", slt, cust);
                found = 1;
            }
        }
    }
    fclose(file);

    if (!found) {
        printf("  (No slots booked yet for this date. All times available!)\n");
    }
    printf("---------------------------------------------------\n");
}

// Slot booking workflow showing existing schedule first
void bookSlot(struct VenueNode* root) {
    char targetVenue[50], customer[50], date[15], slot[20];

    printf("\n--- BST Venue Search ---\nEnter Venue Name: ");
    fgets(targetVenue, sizeof(targetVenue), stdin);
    targetVenue[strcspn(targetVenue, "\n")] = '\0';

    struct VenueNode* venue = searchVenueBST(root, targetVenue);
    if (!venue) {
        printf("Error: Venue '%s' not found in BST registry!\n", targetVenue);
        return;
    }

    printf("Venue Found! Enter Date (DD-MM-YYYY): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';

    // Show currently booked schedule for this specific venue & date
    showBookedSlots(venue->name, date);

    printf("Enter Customer Name: ");
    fgets(customer, sizeof(customer), stdin);
    customer[strcspn(customer, "\n")] = '\0';

    printf("Enter Available Slot (e.g. 04:00PM-05:00PM): ");
    fgets(slot, sizeof(slot), stdin);
    slot[strcspn(slot, "\n")] = '\0';

    int bookingId = rand() % 9000 + 1000;

    FILE *file = fopen("bookings.txt", "a");
    if (file) {
        fprintf(file, "%d,%s,%s,%s,%s,%.2f\n", bookingId, customer, venue->name, date, slot, venue->price);
        fclose(file);
        printf("\nPayment Successful! Booked '%s' for %s [%s]. Booking ID: %d\n",
               venue->name, date, slot, bookingId);
    }
}

void changeBookingDate() {
    int targetId, updated = 0;
    char newDate[15], line[200];
    
    printf("\n--- Change Booking Date ---\nEnter Booking ID: ");
    if (scanf("%d", &targetId) != 1) return;
    while (getchar() != '\n');
    
    printf("Enter New Date (DD-MM-YYYY): ");
    fgets(newDate, sizeof(newDate), stdin);
    newDate[strcspn(newDate, "\n")] = '\0';

    FILE *file = fopen("bookings.txt", "r");
    FILE *temp = fopen("temp_bookings.txt", "w");
    if (!file || !temp) {
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        int bId; char cust[50], ven[50], dt[15], slt[20]; double prc;
        if (sscanf(line, "%d,%49[^,],%49[^,],%14[^,],%19[^,],%lf", &bId, cust, ven, dt, slt, &prc) == 6) {
            if (bId == targetId) {
                strcpy(dt, newDate);
                updated = 1;
            }
            fprintf(temp, "%d,%s,%s,%s,%s,%.2f\n", bId, cust, ven, dt, slt, prc);
        }
    }
    fclose(file); 
    fclose(temp);
    remove("bookings.txt"); 
    rename("temp_bookings.txt", "bookings.txt");

    if (updated) {
        printf("Date updated successfully to %s for Booking ID %d\n", newDate, targetId);
    } else {
        printf("Error: Booking ID %d not found.\n", targetId);
    }
}