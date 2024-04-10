#ifndef JUAL_H
#define JUAL_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Jual: public Command {
    private:
        /**
         * @brief get the location from user input. Can be used to validate if any building is choosen by player other than Walikota
         * 
         * @return vector<Location> 
         */
        vector<Location> promptChoosenLocation(Player*);
        
        /**
         * @brief pop the resource and add the price based on value from promptChoosenLocation
         */
        void popAndAddMoneyFromInventory(Player*, vector<Location>&);

    public:
        Jual(State&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif