#include "tubesoop1/resource/creature.h"
#include "tubesoop1/resource/creature_exception.h"


Creature::Creature(string code, string name, int price, vector<Product*> drops):
    Resource(code,name,price),
    drops(drops)
{
}

Creature::Creature(Creature& other):
    Resource(other.code,other.name,other.price),
    drops(other.drops)
{
}

Creature::~Creature(){
    // for (int i = 0; i < drops.size(); i++){
    //     delete drops[i];
    // }
}

Creature& Creature::operator=(const Creature &other){
    code = other.code;
    name = other.name;
    price = other.price;
    drops = other.drops;
    return *this;
}
Creature& Creature::operator<<(Product& prod){
    this->drops.push_back(&prod);
    return *this;
}

ostream& operator<<(ostream& os, Creature& c){
    if(c.isHarvestable()) os << "\033[1;32m";
    else os << "\033[1;31m";
    os << c.getCode() << "\033[0m\n";
    return os;
}

vector<Product*>& Creature::harvest(){
    // if(!isHarvestable()) throw NotHarvestableException(*this); // this wont happen for user, only in development
    return drops;
}