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
#include "tubesoop1/player/playervisitorpattern.h"
#include <algorithm>

using namespace std;

class State {
    private:
        vector<Player*> playerList;
        Shop shop;
        const char* getClassName(Player &player);
        int turn;
        ResourceFactory* factory;

        // Visitor pattern to get class string without any typeid/dynamic_cast or player returning a type string
        class ClassVisitor : public CommanderVisitor{
            private:
                string className;
            public:
                string get();
                void execute(Player*);
                void execute(Petani*);
                void execute(Peternak*);
                void execute(Walikota*);
        };
    public:
        /**
         * @brief For lazy loaded state
         */
        State();


        State(string statePath, ResourceFactory &factory);
        
        /**
         * @brief Creating new state without loading from file
         */
        State(ResourceFactory &factory);
        ~State();

        /**
         * @brief Save state to file
         */
        void save(string statePath);

        /**
         * @brief Load new state without loading from file
         */
        void loadNew(ResourceFactory &factory);
        
        /**
         * @brief Load state from file
         */
        void load(string statePath, ResourceFactory &factory);

        /**
         * @brief Add player to the playerList
         */
        void addPlayer(string type, string name);

        /**
         * @brief valid only if type is Petani or Peternak
         */
        bool isAddedTypeValid(string &type);

        /**
         * @brief true if player with name already exist on the playerList
         */
        bool isPlayerExist(string name);

        /**
         * @brief Get the Current Player object based on turn
         */
        Player* getCurrentPlayer();

        /**
         * @brief Get the Total Player object
         */
        int getTotalPlayer();

        /**
         * @brief Increment turn by 1
         */
        void nextTurn();

        /**
         * @brief Get the Player object at index
         */
        Player *getPlayer(int index);
        
        /**
         * @brief Get the Player List object
         */
        vector<Player *> &getPlayerList();
        /**
         * @brief Call factory to translate itemName to Resource
         * 
         * @param itemName 
         * @return Resource* 
         */
        Resource* translate(string itemName);

        /**
         * @brief Get the Turn object
         */
        int getTurn();

        /**
         * @brief Add item to the shop
         */
        void addShopItem(Quantifiable<Resource*> item);

        /**
         * @brief Cancel to buy an item from a stock
        */
        void cancelBuyShopItem(int idxItem, int quantity);

        /**
         * @brief get the recipe for buildings
         */
        map<string, Building*>& getRecipeMap();

        Shop& getShop();

        /**
         * @brief Get the Winning Player object. If there is no winning player, return false
         */
        bool tryGetWinningPlayer(Player* player);
};

#endif