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

class State {
    private:
        vector<Player*> playerList;
        Shop shop;
        const char* getClassName(Player &player);
        int turn;
    public:
        /**
         * @brief For lazy loaded state
         */
        State();


        State(string statePath, ResourceFactory &factory);
        
        /**
         * @brief Creating new state without loading from file
         * 
         * @param factory 
         */
        State(ResourceFactory &factory);
        ~State();
        void save(string statePath);
        void loadNew(ResourceFactory &factory);
        void load(string statePath, ResourceFactory &factory);
        void addPlayer(string type, string name);

        Player* getCurrentPlayer();
        int getTotalPlayer();

        /**
         * @brief Increment turn by 1
         */
        void nextTurn();

        Player *getPlayer(int index);
        vector<Player *> getPlayerList();
};

#endif