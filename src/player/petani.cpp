#include "tubesoop1/player/petani.h"
#include "tubesoop1/player/walikota.h"
#include <algorithm>

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

TaxReport* Petani::bayarPajak(Walikota &walikota)
{
    int tax = calculateTax();
    return new TaxReport(username, "Petani", tax);
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


vector<Quantifiable<Plant *>>* Petani::getAllHarvestablePlant(){
    vector<Quantifiable<Plant *>> *harvestablePlant = new vector<Quantifiable<Plant *>>();
    for(Location l : ladang){
        Plant *p = ladang[l];
        if(p->isHarvestable()){
            // Find the plant in the vector, increment if found
            bool found = false;
            for(auto &q : *harvestablePlant){
                if(q.getValue() == p){
                    q++;
                    found = true;
                    break;
                }
            }

            // If not found, add it to the vector
            if(!found) harvestablePlant->push_back(Quantifiable<Plant *>(p, 1));
        }
    }
    return harvestablePlant;
}

bool Petani::isCanBuy(Building*){
    return false;
}

bool Petani::isCanBuy(Plant*){
    return true;
}
bool Petani::isCanBuy(Product*){
    return true;
}

bool Petani::isCanBuy(Animal*){
    return false;
}
