#ifndef MAKAN_H
#define MAKAN_H

#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>

class Makan: public Command {
    public:
        Makan(State&, MainWindow&);
        // visitor pattern
        void execute(Player*);
};

#endif