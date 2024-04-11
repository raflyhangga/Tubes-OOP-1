#include "tubesoop1/player/peternak.h"
#include "tubesoop1/player/walikota.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/resourcevisitorpattern/taker.hpp"
#include "tubesoop1/animal/herbivore.h"



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

vector<Quantifiable<Animal *>>* Peternak::getAllHarvestableAnimal(){
    vector<Quantifiable<Animal *>> *harvestableAnimal = new vector<Quantifiable<Animal *>>();
    for(Location l : peternakan){
        Animal *p = peternakan[l];
        if(p->isHarvestable()){
            // Find the Animal in the vector, increment if found
            bool found = false;
            for(auto &q : *harvestableAnimal){
                if(q.getValue() == p){
                    q++;
                    found = true;
                    break;
                }
            }

            // If not found, add it to the vector
            if(!found) harvestableAnimal->push_back(Quantifiable<Animal *>(p, 1));
        }
    }
    return harvestableAnimal;
}
int Peternak::countAnimalInventory(){
    Taker<Animal> taker;
    int count = 0;
    for(const auto &l : inventory){
        Resource* r = inventory[l];
        try{
            taker.take(r)->get();
            count++;
        } catch(NotTakableException &e) {
        } catch(exception &e) {
        }
    }
    return count;
}

bool Peternak::isCanBuy(Building*){
    return false;
}
bool Peternak::isCanBuy(Plant*){
    return false;
}
bool isCanBuy(Product*){
    return true;
}
bool isCanBuy(Animal*){
    return true;
}
