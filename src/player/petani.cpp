#include "tubesoop1/player/petani.h"
#include "tubesoop1/player/walikota.h"

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

void Petani::addAllPlantAge(int age){
    for(Location l : ladang){
        Plant *p = ladang.getElement(l);
        p->addAge(age);
    }
}

TaxReport Petani::bayarPajak(Walikota &walikota)
{
    int tax = calculateTax();
    return TaxReport(username, "Petani", tax);
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