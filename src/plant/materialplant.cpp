#include "tubesoop1/plant/plant.h"

// <ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>

istream &operator>>(istream &is, MaterialPlant &p)
{
    return is;
}

ostream &operator<<(ostream &os, const MaterialPlant &p)
{
    return os;
}