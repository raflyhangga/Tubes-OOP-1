#ifndef MATERIAL_PLANT_H
#define MATERIAL_PLANT_H

#include <string>
#include "./plant.h"
using namespace std;

// <ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>
class MaterialPlant : Plant
{
public:
    string getType() override;
};

#endif