#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
using namespace std;
#include "resepbangunan.h"
#include "../resource/resource.h"
class Building:Resource
{
private:
    string name;
    ResepBangunan resep;

public:
    Building(string name, ResepBangunan &resep);
    void printBuildingInfo();
    void bangun();

};

#endif