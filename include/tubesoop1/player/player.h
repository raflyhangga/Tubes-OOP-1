#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "tubesoop1/grid.hpp"
#include "tubesoop1/resource/resource.h"
using namespace std;

class Player
{
protected:
    const string username;
    int beratBadan;
    int uang;
    Grid<Resource> inventory;
public:
    static int playerCount;
    Player(string username);

    void putInventory(Resource r);
    void putInventoryAt(Resource r, Location location);
};

#endif