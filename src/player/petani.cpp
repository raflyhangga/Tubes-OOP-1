#include "tubesoop1/player/petani.h"

Petani::Petani(string &_username) : Player(_username) {}

void Petani::putLadang(Plant &p)
{
    ladang.insert(&p);
}

void Petani::putLadangAt(Plant &p, Location &l)
{
    ladang.setElement(l, &p);
}

Grid<Plant*>& Petani::getLadang()
{
    return ladang;
}

void Petani::incrementAllPlantAge(){
    for(Location l : ladang){
        Plant *p = ladang.getElement(l);
        p->incrementAge();
    }
}

TaxReport Petani::bayarPajak(Walikota &walikota)
{
    int totalTax = 0;
    return TaxReport(username, "Petani", totalTax);
}

// visitor pattern
void Petani::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}
