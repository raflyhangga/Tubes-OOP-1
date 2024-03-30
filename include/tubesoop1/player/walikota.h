#ifndef WALIKOTA_H
#define WALIKOTA_H

#include "player.h"
#include "resource/resource.h"
#include <vector>

class Walikota: public Player{
    private:
        vector<Resource> listInventory;
    public:
        Walikota(string,int,int);
};

#endif