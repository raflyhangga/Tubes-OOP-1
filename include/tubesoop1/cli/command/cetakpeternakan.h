#ifndef CETAKPETERNAKAN_H
#define CETAKPETERNAKAN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class CetakPeternakan: public Command {
    public:
        CetakPeternakan(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);

        void print(Grid<Animal*>&);
};

#endif