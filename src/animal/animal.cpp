#include "tubesoop1/animal/animal.h"
#include <tubesoop1/cli/pcolor.h>

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

bool Animal::operator==(const Animal &a)
{
    return getCode() == a.getCode() && getName() == a.getName() && getPrice() == a.getPrice() && weightToHarvest == a.weightToHarvest && weight == a.weight;
}

void Animal::eat(EatenElement &p)
{
    p.eaten(*this);
}

ostream &operator<<(ostream &os, const Animal &a)
{
    if(a.isHarvestable()) {
        for (auto &c: a.getCode()) {
            print_green(c);
        }
    } else {
        for (auto &c: a.getCode()) {
            print_red(c);
        }
    }
    return os;
}

void Animal::taken(TakerVisitor* t){
    t->take(this);
}

int Animal::getWeightToHarvest() const{
    return weightToHarvest;
}