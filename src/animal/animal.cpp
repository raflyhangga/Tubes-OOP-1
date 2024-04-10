#include "tubesoop1/animal/animal.h"

Animal::Animal(string code, string name, int price, int weightToHarvest, vector<Product*> drops): Creature(code,name,price,drops)
{
    weight = 0;
    this->weightToHarvest = weightToHarvest;
}

void Animal::setWeight(int weight)
{
    this->weight = weight;
}
int Animal::getWeight() const
{
    return weight;
}

bool Animal::isHarvestable() const
{
    return weight >= weightToHarvest;
}

void Animal::eat(EatenElement &p)
{
    p.eaten(*this);
}

ostream &operator<<(ostream &os, const Animal &a)
{
    if(a.isHarvestable()) os << "\033[1;32m";
    else os << "\033[1;31m";
    os << a.getCode() << "\033[0m";
    return os;
}

void Animal::taken(TakerVisitor* t){
    t->take(this);
}