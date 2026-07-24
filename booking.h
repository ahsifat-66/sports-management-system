#ifndef BOOKING_H
#define BOOKING_H

struct Booking {
    int bookingId;
    char customerName[50];
    char gameName[30];
    char timeSlot[20];
    int hours;
    double totalBill;
};

void bookGame(int isAdmin);
int doesGameExist(char *game);
double getGamePrice(char *game);

#endif