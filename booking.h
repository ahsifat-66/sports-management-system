#ifndef BOOKING_H
#define BOOKING_H

struct VenueNode {
    int id;
    char name[50];
    char area[50];
    char sport[30];
    double price;
    struct VenueNode *left;
    struct VenueNode *right;
};

struct VenueNode* insertVenue(struct VenueNode* root, int id, const char* name, const char* area, const char* sport, double price);
struct VenueNode* searchVenueBST(struct VenueNode* root, const char* name);
void displayVenuesBST(struct VenueNode* root);

#endif