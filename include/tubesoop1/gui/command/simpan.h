#ifndef SIMPAN_H
#define SIMPAN_H

#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>

class Simpan: public Command {
    public:
        Simpan(State&, MainWindow&);

        // visitor pattern
        void execute(Player*);
};

#endif