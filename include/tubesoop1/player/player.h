#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/resource/resource.h"

using namespace std;
class Player
{
protected:
    const string username;
    int weight;
    int money;
    Grid<Resource *> inventory;

public:
    static int playerCount;
    static int weightToWin;
    static int moneyToWin;
    Player(string &_username);
    virtual ~Player();

    void putInventory(Resource &r);
    void putInventoryAt(Resource &r, Location &location);
    void printInventory();

    string getUsername();
    Grid<Resource *> &getInventory(); // Mengembalikan referensi ke Grid<Resource *>
    void setMoney(int money);
    void removeInventory(Resource &r, int quantity);
    int getWeight();
    int getMoney();

    bool isWin();

};

#endif