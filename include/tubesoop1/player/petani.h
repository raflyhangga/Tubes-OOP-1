#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
#include "tubesoop1/plant/plant.h"
#include "tubesoop1/player/petani.h"
#include "tubesoop1/quantifiable/quantifiable.hpp"
#include <set>
using namespace std;

class Petani : public Player
{
private:
    Grid<Plant*> ladang;
    int getNetWealth();
    int getKTKP();
public:
    Petani(string &username);

    void putLadang(Plant &p);
    void putLadangAt(Plant &p, Location &l);
    Grid<Plant*>& getLadang();

    void addAllPlantAge(int age);
    TaxReport *bayarPajak(Walikota &walikota);
    
    vector<Quantifiable<Plant *>>* getAllHarvestablePlant();

    // visitor pattern
    void executed(CommanderVisitor&);
};

#endif