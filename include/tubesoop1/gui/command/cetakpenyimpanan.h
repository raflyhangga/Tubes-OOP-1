#ifndef CETAK_PENYIMPANAN_H
#define CETAK_PENYIMPANAN_H

#include <iostream>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
using namespace std;

class CetakPenyimpanan : public Command { // visitor pattern
    public:
        CetakPenyimpanan(State&, MainWindow&);

        // visitor pattern
        void execute(Player*);

};



#endif