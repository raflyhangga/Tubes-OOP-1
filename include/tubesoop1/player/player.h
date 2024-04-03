#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class Player
{
protected:
    string username;
    int beratBadan;
    int uang;
    // grid<Resource> inventory;
public:
    static int playerCount;
    Player();
    Player(string username, int beratBadan, int uang);
    friend ostream &operator<<(ostream &os, const Player &a);
    friend istream &operator>>(istream &is, Player &a);
};

#endif