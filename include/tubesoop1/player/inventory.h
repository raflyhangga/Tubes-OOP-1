#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/plant/plant.h"
using namespace std;

class Inventory : Grid<Plant>
{
public:
    static int width;
    static int height;
    Inventory();
};

#endif