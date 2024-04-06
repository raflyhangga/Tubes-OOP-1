#include "tubesoop1/product/product.h"
#include "tubesoop1/animal/animal_exception.h"

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
void ProductAnimal::eaten(EaterVisitor &a)
{
    a.eat(*this);
}

ProductFruit::ProductFruit(string code, string name, int price, int addedWeight) : Product(code, name, price, addedWeight){
    
}
void ProductFruit::eaten(EaterVisitor &a)
{
    a.eat(*this);
}

ProductMaterial::ProductMaterial(string code, string name, int price, int addedWeight) : Product(code, name, price, addedWeight){
    
}
void ProductMaterial::eaten(EaterVisitor &a)
{
    a.eat(*this);
}