#include "tubesoop1/resource/creature.h"


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
    for (int i = 0; i < drops.size(); i++){
        delete drops[i];
    }
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