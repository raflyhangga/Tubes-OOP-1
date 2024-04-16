#ifndef CETAK_LADANG_H
#define CETAK_LADANG_H

#include <iostream>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
using namespace std;

class CetakLadang : public Command { // visitor pattern
    public:
        CetakLadang(State&, MainWindow&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);

        string getInfo(Grid<Plant *> &ladang);

};



#endif