#ifndef NEXT_H
#define NEXT_H

#include <iostream>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
using namespace std;

class Next : public Command { // visitor pattern
    private:
        string turnInfo();
    public:
        Next(State&, MainWindow&);

        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);

};



#endif