#ifndef PETERNAKAN_H
#define PETERNAKAN_H

#include <string>
#include <iostream>
#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/animal/animal.h"
using namespace std;

class Peternakan : Grid<Animal>
{
public:
    static int width;
    static int height;
    Peternakan();
};

#endif