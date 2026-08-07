#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "booking.h"

struct Booking {
    int bookingId;
    char customerName[50];
    char venueName[50];
    char date[15];
    char slot[20];
    double paymentAmount;
};

void showBookedSlots(const char* venueName, const char* date);
void bookSlot(struct VenueNode* root);
void changeBookingDate();

#endif