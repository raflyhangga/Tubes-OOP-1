#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/player/playervisitorpattern.h"
#include "tubesoop1/player/taxreport.h"

using namespace std;
class Player : public PlayerElement // visitor pattern
{
protected:
    const string username;
    int weight;
    int money;
    Grid<Resource *> inventory;
    
    virtual int getNetWealth();
    int getKKPRate();
    virtual int getKTKP() = 0;
    int getKKP();
public:
    static int playerCount;
    static int weightToWin;
    static int moneyToWin;
    Player(string &_username);
    virtual ~Player();

    void putInventory(Resource &r);
    void putInventoryAt(Resource &r, Location &location);
    Grid<Resource*>& getInventory();

    void setWeight(int weight);
    void setMoney(int money);
    void addMoney(int money);

    string getUsername();
    void removeInventory(Resource &r, int quantity);

    void removeInvetoryAt(Location &location);
    int getWeight();
    int getMoney();

    bool isWin();

    virtual TaxReport* bayarPajak(Walikota &walikota) = 0;
    
    int calculateTax();

    // Visitor pattern
    virtual void executed(CommanderVisitor&) = 0;
};

#endif