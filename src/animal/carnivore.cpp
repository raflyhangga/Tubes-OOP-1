#include "tubesoop1/animal/carnivore.h"

Carnivore::Carnivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops) : Animal(code,name,price,weightToHarvest,drops){}
void Carnivore::eat(ProductAnimal &p)
{
    weight += p.getAddedWeight();
}
void Carnivore::eat(ProductFruit &p)
{
    throw CannotEatException(*this, p);
}
void Carnivore::eat(ProductMaterial &p)
{
    throw CannotEatException(*this, p);
}
