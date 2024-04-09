#include "tubesoop1/player/peternak.h"
#include "tubesoop1/player/walikota.h"



Peternak::Peternak(string &_username) : Player(_username) {}

void Peternak::putPeternakan(Animal &h)
{
    peternakan.insert(&h);
}

void Peternak::putPeternakanAt(Animal &h, Location &l)
{
    peternakan.setElement(l, &h);
}

Grid<Animal*>& Peternak::getPeternakan()
{
    return peternakan;
}

TaxReport *Peternak::bayarPajak(Walikota &walikota)
{
    int tax = calculateTax();
    walikota.addMoney(tax);
    return new TaxReport(username, "Peternak", tax);
}

// visitor pattern
void Peternak::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}


int Peternak::getNetWealth(){
    int totalMoney = Player::getNetWealth();
    for(Location l : peternakan){
        totalMoney += peternakan[l]->getPrice();
    }
    return totalMoney;
}
int Peternak::getKTKP(){
    return 11;
}


