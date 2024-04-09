#ifndef CETAKLADANG_H
#define CETAKLADANG_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class CetakLadang: public Command {
    public:
        CetakLadang(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);

        void printLabelAndGrid(Petani *petani, Grid<Plant *> &ladang);
};

#endif