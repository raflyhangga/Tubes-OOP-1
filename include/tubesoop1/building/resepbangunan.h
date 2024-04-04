#ifndef RESEP_BANGUNAN_H
#define RESEP_BANGUNAN_H

#include <iostream>
#include <vector>
#include "material.h"
using namespace std;

class ResepBangunan
{
private:
    string kodeHuruf;
    string name;
    vector<Material> materials; 
    int price;

public:
    // User defined constructor
    ResepBangunan(string kodeHuruf, string name, const vector<Material>& materials, int price);

    void printMaterialInfo();

    // Operator +=
    ResepBangunan& operator+=(const Material& material);

    // Copy constructor
    ResepBangunan(const ResepBangunan& other);
};

#endif
