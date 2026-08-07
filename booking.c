#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "booking.h"

struct VenueNode* createVenueNode(int id, const char* name, const char* area, const char* sport, double price) {
    struct VenueNode* newNode = (struct VenueNode*)malloc(sizeof(struct VenueNode));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->area, area);
    strcpy(newNode->sport, sport);
    newNode->price = price;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct VenueNode* insertVenue(struct VenueNode* root, int id, const char* name, const char* area, const char* sport, double price) {
    if (root == NULL) {
        return createVenueNode(id, name, area, sport, price);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertVenue(root->left, id, name, area, sport, price);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertVenue(root->right, id, name, area, sport, price);
    }
    return root;
}

struct VenueNode* searchVenueBST(struct VenueNode* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return searchVenueBST(root->left, name);
    }
    return searchVenueBST(root->right, name);
}

void displayVenuesBST(struct VenueNode* root) {
    if (root != NULL) {
        displayVenuesBST(root->left);
        printf("Venue: %-18s | Area: %-10s | Sport: %-10s | Rate: $%.2f/hr\n",
               root->name, root->area, root->sport, root->price);
        displayVenuesBST(root->right);
    }
}