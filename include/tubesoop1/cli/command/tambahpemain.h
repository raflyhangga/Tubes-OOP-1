#ifndef TAMBAH_PEMAIN_H
#define TAMBAH_PEMAIN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class TambahPemain: public Command {
    public:
        TambahPemain(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif