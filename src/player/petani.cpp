#include "tubesoop1/player/petani.h"
#include "tubesoop1/player/walikota.h"
#include <algorithm>

vector<Petani*> Petani::listPetani;
Petani::Petani(string &_username) : Player(_username) {
    listPetani.push_back(this);
}

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

void Petani::incrementAllPlantAge(){
    for(Petani *p : listPetani){
        Grid<Plant*> ladangtemp = p->getLadang();
        for(Location l : ladangtemp){
            Plant *plant = ladangtemp.getElement(l);
            plant->addAge(1);
        }
    }
}

TaxReport* Petani::bayarPajak(Walikota &walikota)
{
    int tax = calculateTax(); 
    money -= tax;
    if(money < 0) {
        tax += money;
        money = 0; // Bayar sesuai kemampuan
    }
    walikota.addMoney(tax);
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
                if(q.getValue()->getCode() == p->getCode()){ // cannot compare with == because the age may be different
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