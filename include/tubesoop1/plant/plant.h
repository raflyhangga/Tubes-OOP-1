#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
using namespace std;

// <ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>
class Plant
{
protected:
    string kode_huruf;
    string name;
    int durationToHarvest;
    int price;

public:
    virtual string getType() = 0;
    friend ostream &operator<<(ostream &os, const Plant &a);
    friend istream &operator>>(istream &is, Plant &a);
};

#endif

// Material Plant
//   Teak Tree -> 1 Teak Wood
//   Sandalwood Tree -> 1 Sandalwood Wood
//   Aloe Tree -> 1 Aloe Wood
//   Ironwood Tree -> 1 Ironwood Wood
// Fruit Plant
//   Apple Tree -> 1 Apple
//   Orange Tree -> 1 Orange
//   Banana Tree -> 1 Banana
