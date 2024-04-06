#include "tubesoop1/animal/animal.h"

Animal::Animal(string id, string code, string name, int price, int weightToHarvest) : Resource(id, code, name, price)
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

Herbivora::Herbivora(string id, string code, string name, int price, int weightToHarvest) : Animal(id, code, name, price, weightToHarvest)
{

}


// return 1 if success, 0 if failed
int Herbivora::makan(Product &p)
{
    ProductFruit* plant = dynamic_cast<ProductFruit*>(&p);
    if(plant != nullptr){
        return 1;
    } 
    else {
        return 0;
    }
}

Karnivora::Karnivora(string id, string code, string name, int price, int weightToHarvest) : Animal(id, code, name, price, weightToHarvest)
{

}

int Karnivora::makan(Product &p)
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

Omnivora::Omnivora(string id, string code, string name, int price, int weightToHarvest) : Animal(id, code, name, price, weightToHarvest)
{

}

int Omnivora::makan(Product &p)
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