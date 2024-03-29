#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

// <ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>
class Animal
{
private:
    string kode_huruf;
    string name;
    int weightToHarvest;
    int price;

public:
    virtual string getType() = 0;
    friend ostream &operator<<(ostream &os, const Animal &a);
    friend istream &operator>>(istream &is, Animal &a);
};

#endif