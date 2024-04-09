#ifndef PETERNAK_H
#define PETERNAK_H

#include <string>
#include "tubesoop1/player/player.h"
#include "tubesoop1/animal/animal.h"
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


    // visitor pattern
    void executed(CommanderVisitor&);

    int countAnimalInventory();
};

#endif