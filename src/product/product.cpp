#include "tubesoop1/product/product.h"

Product::Product(string id, string code, string name, int price,string origin, int addedWeight) : Resource(id, code, name, price)
{
    this->origin = origin;
    this->addedWeight = addedWeight;
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

bool operator==(const Product &p1, const Product &p2)
{
    return p1.getId() == p2.getId();
}

ProductAnimal::ProductAnimal(string id, string code, string name, int price, string origin, int addedWeight) : Product(id, code, name, price, origin, addedWeight){
    
}

ProductFruit::ProductFruit(string id, string code, string name, int price, string origin, int addedWeight) : Product(id, code, name, price, origin, addedWeight){
    
}

ProductMaterial::ProductMaterial(string id, string code, string name, int price, string origin, int addedWeight) : Product(id, code, name, price, origin, addedWeight){
    
}