#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "booking.h"
#include "schedule.h"

int main() {
    struct VenueNode* root = NULL;
    root = insertVenue(root, 1, "Daffodil Futsal", "Ashulia", "Football", 1200.0);
    root = insertVenue(root, 2, "DIU Indoor", "Ashulia", "Badminton", 500.0);
    root = insertVenue(root, 3, "Mirpur Arena", "Mirpur", "Cricket", 2000.0);

    int choice;
    while (1) {
        printf("\n==========================================\n");
        printf("  DAFFODIL SPORTS MANAGEMENT SYSTEM \n");
        printf("==========================================\n");
        printf("1. Admin Login\n");
        printf("2. Venue Provider Portal (Sign Up / Login)\n");
        printf("3. Customer / Student Portal (Sign Up / Login)\n");
        printf("4. Exit System\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n');

        // --- 1. ADMIN ---
        if (choice == 1) {
            if (adminLogin()) {
                int adminChoice;
                while (1) {
                    printf("\n--- Admin Dashboard ---\n");
                    printf("1. Add Game Pricing\n");
                    printf("2. Delete Game\n");
                    printf("3. View All Games\n");
                    printf("4. Logout\n");
                    printf("Choice: ");
                    if (scanf("%d", &adminChoice) != 1) { while (getchar() != '\n'); continue; }
                    while (getchar() != '\n');

                    if (adminChoice == 1) addGame();
                    else if (adminChoice == 2) deleteGame();
                    else if (adminChoice == 3) viewGames();
                    else if (adminChoice == 4) break;
                }
            }
        } 
        // --- 2. VENUE PROVIDER PORTAL ---
        else if (choice == 2) {
            int authChoice;
            printf("\n--- Venue Provider Portal ---\n");
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("Choice: ");
            if (scanf("%d", &authChoice) != 1) { while (getchar() != '\n'); continue; }
            while (getchar() != '\n');

            if (authChoice == 1) {
                providerSignUp();
            } else if (authChoice == 2) {
                if (providerLogin()) {
                    int providerChoice;
                    while (1) {
                        printf("\n--- Venue Provider Dashboard ---\n");
                        printf("1. Add / Register New Venue\n");
                        printf("2. View Registered Venues (BST Tree)\n");
                        printf("3. Logout\n");
                        printf("Choice: ");
                        if (scanf("%d", &providerChoice) != 1) { while (getchar() != '\n'); continue; }
                        while (getchar() != '\n');

                        if (providerChoice == 1) {
                            int vId;
                            char vName[50], vArea[50], vSport[30];
                            double vPrice;

                            printf("\n--- Add Venue Details ---\n");
                            printf("Enter Venue ID: ");
                            scanf("%d", &vId);
                            while (getchar() != '\n');

                            printf("Enter Venue Name: ");
                            fgets(vName, sizeof(vName), stdin);
                            vName[strcspn(vName, "\n")] = '\0';

                            printf("Enter Area: ");
                            fgets(vArea, sizeof(vArea), stdin);
                            vArea[strcspn(vArea, "\n")] = '\0';

                            printf("Enter Sport Type: ");
                            fgets(vSport, sizeof(vSport), stdin);
                            vSport[strcspn(vSport, "\n")] = '\0';

                            printf("Enter Price Per Hour: ");
                            scanf("%lf", &vPrice);
                            while (getchar() != '\n');

                            root = insertVenue(root, vId, vName, vArea, vSport, vPrice);
                            printf("Venue '%s' added successfully!\n", vName);
                        }
                        else if (providerChoice == 2) {
                            printf("\n--- Registered Venues List (A-Z) ---\n");
                            displayVenuesBST(root);
                        }
                        else if (providerChoice == 3) break;
                    }
                }
            }
        }
        // --- 3. CUSTOMER PORTAL ---
        else if (choice == 3) {
            int authChoice;
            printf("\n--- Customer / Student Portal ---\n");
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("Choice: ");
            if (scanf("%d", &authChoice) != 1) { while (getchar() != '\n'); continue; }
            while (getchar() != '\n');

            if (authChoice == 1) {
                customerSignUp();
            } else if (authChoice == 2) {
                if (customerLogin()) {
                    int custChoice;
                    while (1) {
                        printf("\n--- Customer Dashboard ---\n");
                        printf("1. View Available Venues\n");
                        printf("2. Search Venue (BST) & Book Slot\n");
                        printf("3. Change Booking Date\n");
                        printf("4. Logout\n");
                        printf("Choice: ");
                        if (scanf("%d", &custChoice) != 1) { while (getchar() != '\n'); continue; }
                        while (getchar() != '\n');

                        if (custChoice == 1) {
                            printf("\n--- Available Venues (A-Z) ---\n");
                            displayVenuesBST(root);
                        }
                        else if (custChoice == 2) bookSlot(root);
                        else if (custChoice == 3) changeBookingDate();
                        else if (custChoice == 4) break;
                    }
                }
            }
        } 
        // --- 4. EXIT ---
        else if (choice == 4) {
            printf("\nExiting system. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}