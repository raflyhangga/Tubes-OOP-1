#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "resepbangunan.h"
#include "../resource/resource.h"
using namespace std;

class Building : public Resource {
private:
    string name;
    ResepBangunan resep;
    int quantity; 

public:
    Building(string name, ResepBangunan &resep, int quantity = 0);
    void printBuildingInfo();
    void bangun(int uang, int);
    void tambahBangunan(int jumlah);
    void kurangiBangunan(int jumlah);
};

#endif
