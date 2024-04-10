#include "tubesoop1/plant/plant.h"

Plant::Plant(string code, string name, int price, int durationToHarvest, vector<Product*> drops):
    Creature(code,name,price,drops)
{
    age = 0;
    this->durationToHarvest = durationToHarvest;
}

void Plant::setAge(int age){
    this->age = age;
}
void Plant::addAge(int age){
    this->age += age;
}
int Plant::getAge(){
    return age;
}
bool Plant::isHarvestable() const{
    return age >= durationToHarvest;
}

Plant::~Plant(){
    
}

// Plant::Plant(Plant& other):
//     Creature(other.code,other.name,other.price,other.)
// {
//     this->durationToHarvest = other.durationToHarvest;
// }
// Plant& operator==(Plant&);



istream &operator>>(istream &is, Plant &p)
{
    return is;
}

ostream &operator<<(ostream &os, const Plant &p)
{
    if(p.isHarvestable()) os << "\033[1;32m";
    else os << "\033[1;31m";
    os << p.getCode() << "\033[0m";
    return os;
}

void Plant::taken(TakerVisitor* t){
    t->take(this);
}