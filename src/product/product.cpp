#include "tubesoop1/product/product.h"

Product::Product(string code, string name, int price, int addedWeight) : Resource(code, name, price)
{
    this->origin = origin;
    this->addedWeight = addedWeight;
}

Product::~Product()
{
}

string Product::getOrigin() const
{
    return origin;
}

int Product::getAddedWeight() const
{
    return addedWeight;
}

void Product::setOrigin(string origin)
{
    this->origin = origin;
}

void Product::setAddedWeight(int addedWeight)
{
    this->addedWeight = addedWeight;
}

ProductAnimal::ProductAnimal(string id, string code, string name, int price, string origin, int addedWeight) : Product(code, name, price, addedWeight){
    
}

ProductFruit::ProductFruit(string id, string code, string name, int price, string origin, int addedWeight) : Product(code, name, price, addedWeight){
    
}

ProductMaterial::ProductMaterial(string id, string code, string name, int price, string origin, int addedWeight) : Product(code, name, price, addedWeight){
    
}