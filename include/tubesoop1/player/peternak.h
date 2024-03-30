#ifndef PETERNAK_H
#define PETERNAK_H

#include "resource/resource.h"
#include "player/player.h"
#include "animal/hewanpeternakan.h"
#include <vector>

class Peternak: public Player{
    private:
        vector<Resource> listInventory;
        vector<HewanPeternakan> peternakan;
    public:
        Peternak(string,int,int);
};

#endif