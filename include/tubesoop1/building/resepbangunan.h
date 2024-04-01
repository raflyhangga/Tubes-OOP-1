#ifndef RESEP_BANGUNAN_H
#define RESEP_BANGUNAN_H
#include <iostream>
using namespace std;
#include "material.h"

class ResepBangunan
{
private:
    string kodeHuruf;
    string name;
    Material &materials;
    int price;

public:
    // Allocation of memory for the material array
    ResepBangunan();
    // User defined constructor
    ResepBangunan(string kodeHuruf, string name, Material &material, int price);
    // Destructor for array of material
    ~ResepBangunan();

    void printMaterialInfo();
    
};

#endif