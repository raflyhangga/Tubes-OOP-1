#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
#include "tubesoop1/plant/plant.h"
#include "tubesoop1/player/petani.h"
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

    void incrementAllPlantAge();
    TaxReport bayarPajak(Walikota &walikota);
    

    // visitor pattern
    void executed(CommanderVisitor&);
};

#endif