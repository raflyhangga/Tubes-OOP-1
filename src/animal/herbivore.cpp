#include "tubesoop1/animal/herbivore.h"

Herbivore::Herbivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops) : Animal(code,name,price,weightToHarvest,drops)
{

}
void Herbivore::eat(ProductAnimal &p)
{
    throw CannotEatException(*this, p);
}
void Herbivore::eat(ProductFruit &p)
{
    weight += p.getAddedWeight();
}
void Herbivore::eat(ProductMaterial &p)
{
    throw CannotEatException(*this, p);
}
