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
