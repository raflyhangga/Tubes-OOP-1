#ifndef JUAL_H
#define JUAL_H

#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
#include <tubesoop1/gui/components/dialog.h>
#include <tubesoop1/gui/components/gridview.hpp>
#include <functional>

class Jual: public Command {
    private:
        /**
         * @brief if user close the dialog without choosing any location, it will return empty vector. if confirming when no location is chosen, it will stay inside and show a messagebox. Second parameter is for validation function. If it returns false, it will return empty vector.
         * 
         * @return vector<Location> 
         */
        vector<Location> promptChoosenLocation(Player*, function<bool(Location)>);
        
        /**
         * @brief pop the resource and add the price based on value from promptChoosenLocation
         */
        void popAndAddMoneyFromInventory(Player*, vector<Location>&);
        
        
    public:
        Jual(State&, MainWindow&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif