#ifndef CETAKPENYIMPANAN_H
#define CETAKPENYIMPANAN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class CetakPenyimpanan: public Command {
    public:
        CetakPenyimpanan(State&);

        // visitor pattern
        void execute(Player*);
};

#endif