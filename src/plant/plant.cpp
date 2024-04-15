#include "tubesoop1/plant/plant.h"
#include <tubesoop1/cli/pcolor.h>

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

bool Plant::operator==(const Plant &a){
    return getCode() == a.getCode() && getName() == a.getName() && getPrice() == a.getPrice() && durationToHarvest == a.durationToHarvest && age == a.age;
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
    if(p.isHarvestable()) {
        for (auto &c: p.getCode()) {
            print_green(c);
        }
    } else {
        for (auto &c: p.getCode()) {
            print_red(c);
        }
    }
}

void Plant::taken(TakerVisitor* t){
    t->take(this);
}