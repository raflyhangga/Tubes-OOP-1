#include "tubesoop1/product/product.h"
#include "tubesoop1/animal/animal_exception.h"

Product::Product(string code, string name, int addedWeight, int price) : Resource(code, name, price)
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

void Product::taken(TakerVisitor* t){
    t->take(this);
}



ProductAnimal::ProductAnimal(string code, string name, int addedWeight, int price) : Product(code, name, addedWeight, price){
    
}
void ProductAnimal::eaten(EaterVisitor &a)
{
    a.eat(*this);
}
void ProductAnimal::taken(TakerVisitor* t){
    t->take(this);
}


ProductFruit::ProductFruit(string code, string name, int addedWeight, int price) : Product(code, name, addedWeight, price){
    
}
void ProductFruit::eaten(EaterVisitor &a)
{
    a.eat(*this);
}

void ProductFruit::taken(TakerVisitor* t){
    t->take(this);
}

ProductMaterial::ProductMaterial(string code, string name, int price, int addedWeight) : Product(code, name, price, addedWeight){
    
}
void ProductMaterial::eaten(EaterVisitor &a)
{
    a.eat(*this);
}

void ProductMaterial::taken(TakerVisitor* t){
    t->take(this);
}