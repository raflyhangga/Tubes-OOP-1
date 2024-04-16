#ifndef CETAK_PETERNAKAN_H
#define CETAK_PETERNAKAN_H

#include <iostream>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
using namespace std;

class CetakPeternakan : public Command { // visitor pattern
    public:
        CetakPeternakan(State&, MainWindow&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);

        string getInfo(Grid<Animal *> &peternakan);

};



#endif