#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "booking.h"
#include "schedule.h"

void viewSchedule();
void viewNoticeBoard();
void updateNoticeBoard();
void bookGame(int isAdmin);
void addGame();
void deleteGame();
void viewGames();
void cancelbooking();
void viewMembers();
int adminLogin();

int main() {
    int roleChoice, adminChoice, customerChoice;

    while (1) {
        printf("\n=========================================\n");
        printf("    Daffodil University Sports MANAGEMENT SYSTEM      \n");
        printf("=========================================\n");
        printf("1. Admin\n2. Customer\n3. Exit System\n");
        printf("Select Role: ");

        if (scanf("%d", &roleChoice) != 1) {
            printf("Invalid selection.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (roleChoice == 3) {
            printf("Exiting system. Goodbye!\n");
            break;
        }

        if (roleChoice == 1) {
            if (!adminLogin()) {
                printf("\nAccess denied. Returning to main menu.\n");
                continue;
            }

            while (1) {
                printf("\n--- Admin Menu ---\n");
                printf("1. View Schedule\n");
                printf("2. View Notice Board & Rules\n");
                printf("3. Update Notice Board\n");
                printf("4. Book Slot\n");
                printf("5. Add New Game Feature\n");
                printf("6. Delete a Game Feature\n");
                printf("7. View All Games\n");
                printf("8. Cancel Booking by ID\n");
                printf("9. View Members (Who Booked)\n");
                printf("10. Back to Main Menu\n");
                printf("Enter choice: ");

                if (scanf("%d", &adminChoice) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');

                if      (adminChoice == 1) viewSchedule();
                else if (adminChoice == 2) viewNoticeBoard();
                else if (adminChoice == 3) updateNoticeBoard();
                else if (adminChoice == 4) bookGame(1);
                else if (adminChoice == 5) addGame();
                else if (adminChoice == 6) deleteGame();
                else if (adminChoice == 7) viewGames();
                else if (adminChoice == 8) cancelbooking();
                else if (adminChoice == 9) viewMembers();
                else if (adminChoice == 10) break;
                else printf("Invalid choice!\n");
            }
        }
        else if (roleChoice == 2) {
            while (1) {
                printf("\n--- Customer Menu ---\n");
                printf("1. View Schedule\n");
                printf("2. View Notice Board & Rules\n");
                printf("3. Book a Game\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");

                if (scanf("%d", &customerChoice) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');

                if      (customerChoice == 1) viewSchedule();
                else if (customerChoice == 2) viewNoticeBoard();
                else if (customerChoice == 3) bookGame(0);
                else if (customerChoice == 4) break;
                else printf("Invalid choice!\n");
            }
        }
        else {
            printf("Invalid role selection!\n");
        }
    }
    return 0;
}