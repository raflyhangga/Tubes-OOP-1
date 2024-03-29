#include "tubesoop1/plant/materialplant.h"

// <ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>

string MaterialPlant::getType()
{
    return "MaterialPlant";
}

istream &operator>>(istream &is, MaterialPlant &p)
{
    return is;
}

ostream &operator<<(ostream &os, const MaterialPlant &p)
{
    return os;
}