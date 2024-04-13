#ifndef TAMBAH_PEMAIN_H
#define TAMBAH_PEMAIN_H

#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class TambahPemain: public Command {
    public:
        TambahPemain(State&, MainWindow&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif