#ifndef PETERNAK_H
#define PETERNAK_H

#include <string>
#include <set>
#include "player.h"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/quantifiable/quantifiable.hpp"
using namespace std;

class Peternak : public Player
{
private:
    Grid<Animal*> peternakan;
    int getNetWealth();
    int getKTKP();
public:
    Peternak(string &username);

    void putPeternakan(Animal &h);
    void putPeternakanAt(Animal &h, Location &l);
    Grid<Animal*> &getPeternakan();
    TaxReport *bayarPajak(Walikota &walikota);

    set<Animal*>* getSetOfAnimal();
    vector<Quantifiable<Animal *>>* getAllHarvestableAnimal();

    // visitor pattern
    void executed(CommanderVisitor&);
};

#endif