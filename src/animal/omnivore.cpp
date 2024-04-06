#include "tubesoop1/animal/omnivore.h"

Omnivore::Omnivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops) : Animal(code,name,price,weightToHarvest,drops)
{

}
void Omnivore::eat(ProductAnimal &p)
{
    weight += p.getAddedWeight();
}
void Omnivore::eat(ProductFruit &p)
{
    weight += p.getAddedWeight();
}
void Omnivore::eat(ProductMaterial &p)
{
    throw CannotEatException(*this, p);
}
