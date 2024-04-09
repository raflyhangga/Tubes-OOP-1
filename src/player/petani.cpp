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
    return TaxReport(username, "Petani", calculateTax());
}

// visitor pattern
void Petani::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}

int Petani::getNetWealth(){
    int totalMoney = Player::getNetWealth();
    for(Location l : ladang){
        totalMoney += ladang[l]->getPrice();
    }
    return totalMoney;
}
int Petani::getKTKP(){
    return 13;
}