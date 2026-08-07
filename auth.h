#ifndef AUTH_H
#define AUTH_H

#define ADMIN_USERNAME "admin"
#define MAX_LOGIN_ATTEMPTS 3

struct Game {
    char name[30];
    double price;
    int duration;
};

// Function prototypes
void compute_md5(const char *input, char output_hex[33]);
int adminLogin();

// Provider Authentication
int providerSignUp();
int providerLogin();

// Customer Authentication
int customerSignUp();
int customerLogin();

// Game Management
void addGame();
void deleteGame();
void viewGames();

#endif