#ifndef PANEN_H
#define PANEN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Panen: public Command {
    public:
        Panen(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif