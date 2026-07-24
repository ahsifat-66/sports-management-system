#ifndef AUTH_H
#define AUTH_H

#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin123"
#define MAX_LOGIN_ATTEMPTS 3

struct Game {
    char name[30];
    double price;
    int duration;
};

int adminLogin();
void addGame();
void deleteGame();
void viewGames();

#endif