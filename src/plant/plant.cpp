#include "tubesoop1/plant/plant.h"

Plant::Plant(string code, string name, int price, int durationToHarvest, vector<Product*> drops):
    Creature(code,name,price,drops)
{
    this->durationToHarvest = durationToHarvest;
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
    return os;
}