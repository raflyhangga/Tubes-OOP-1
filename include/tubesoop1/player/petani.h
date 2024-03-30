#ifndef PETANI_H
#define PETANI_H

#include "resource/resource.h"
#include "player/player.h"
#include "plant/tanamanladang.h"
#include <vector>


class Petani: public Player{
    private:
        vector<Resource&> listInventory;
        vector<TanamanLadang> ladang;
    public:
        Petani(string,int,int);
};

#endif