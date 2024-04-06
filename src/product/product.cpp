#include "tubesoop1/product/product.h"

Product::Product(string code, string name, int price, int addedWeight) : Resource(code, name, price)
{
    this->addedWeight = addedWeight;
}

Product::~Product()
{
}



int Product::getAddedWeight() const
{
    return addedWeight;
}



void Product::setAddedWeight(int addedWeight)
{
    this->addedWeight = addedWeight;
}

ProductAnimal::ProductAnimal(string code, string name, int price, int addedWeight) : Product(code, name, price, addedWeight){
    
}

ProductFruit::ProductFruit(string code, string name, int price, int addedWeight) : Product(code, name, price, addedWeight){
    
}

ProductMaterial::ProductMaterial(string code, string name, int price, int addedWeight) : Product(code, name, price, addedWeight){
    
}