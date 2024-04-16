#ifndef PUNGUT_PAJAK_H
#define PUNGUT_PAJAK_H

#include <iostream>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
using namespace std;

class PungutPajak : public Command { // visitor pattern
    public:
        PungutPajak(State&, MainWindow&);

        // visitor pattern
        void execute(Walikota*);
        void execute(Petani*);
        void execute(Peternak*);

};



#endif