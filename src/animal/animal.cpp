#include "tubesoop1/animal/animal.h"

Animal::Animal(string code, string name, int price, int weightToHarvest, vector<Product*> drops): Creature(code,name,price,drops)
{
    this->weightToHarvest = weightToHarvest;
}

Animal::~Animal()
{

}

void Animal::setWeightToHarvest(int weightToHarvest)
{
    this->weightToHarvest = weightToHarvest;
}

int Animal::getWeightToHarvest() const
{
    return weightToHarvest;
}

Herbivore::Herbivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops) : Animal(code,name,price,weightToHarvest,drops)
{

}


// return 1 if success, 0 if failed
int Herbivore::makan(Product &p)
{
    ProductFruit* plant = dynamic_cast<ProductFruit*>(&p);
    if(plant != nullptr){
        return 1;
    } 
    else {
        return 0;
    }
}

Carnivore::Carnivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops) : Animal(code,name,price,weightToHarvest,drops)
{

}

int Carnivore::makan(Product &p)
{
    ProductAnimal* Panimal = dynamic_cast<ProductAnimal*>(&p);
    if(Panimal != nullptr){
        // eat success
        return 1; 
    } 
    else {
        return 0;
    }
}

Omnivore::Omnivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops) : Animal(code,name,price,weightToHarvest,drops)
{

}

int Omnivore::makan(Product &p)
{
    ProductMaterial* material = dynamic_cast<ProductMaterial*>(&p);
    
    if(material == nullptr){
        // eat success
        return 1;
    } 
    else {
        return 0;
    }
}

// int main(){
//     // make a test
//     ProductFruit apple("1", "APL", "Apple", 1000, "Indonesia", 10);
//     ProductAnimal cow("2", "COW", "Cow", 1000, "Indonesia", 10);
//     ProductMaterial wood("3", "WOD", "Wood", 1000, "Indonesia", 10);
//     Karnivora lion("4", "LIO", "Lion", 1000, 10);
//     Herbivora rabbit("5", "RAB", "Rabbit", 1000, 10);
//     Omnivora bear("6", "BEA", "Bear", 1000, 10);
//     cout << lion.makan(apple) << endl;
// }