#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/player/inventory.h"
using namespace std;

class Player
{
protected:
    const string username;
    int beratBadan;
    int uang;
    Inventory inventory;
public:
    static int playerCount;
    static int weightToWin;
    static int moneyToWin;
    Player(string &_username);

    void putInventory(Resource &r);
    void putInventoryAt(Resource &r, Location &location);

    bool isWin();
};

#endif