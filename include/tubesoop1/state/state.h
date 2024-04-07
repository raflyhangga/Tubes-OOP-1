#ifndef STATE_H
#define STATE_H

#include <vector>
#include <fstream>
#include "tubesoop1/player/player.h"
#include "tubesoop1/player/petani.h"
#include "tubesoop1/player/peternak.h"
#include "tubesoop1/player/walikota.h"
#include "tubesoop1/resource/resourcefactory.h"
#include "tubesoop1/resource/resourcefactory_exception.h"
#include "tubesoop1/grid/location.h"
#include "tubesoop1/state/state_exception.h"
#include "tubesoop1/shop/shop.h"
#include <algorithm>

using namespace std;

// Temporary class;
// class Shop {

// };

class State {
    private:
        vector<Player*> playerList;
        Shop shop;
        const char* getClassName(Player &player);
    public:
        State(string statePath, ResourceFactory &factory);
        void save(string statePath);
        void load(string statePath, ResourceFactory &factory);
        void addPlayer(string type, string name);
};

#endif