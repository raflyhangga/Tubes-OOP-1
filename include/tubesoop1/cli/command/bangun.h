#ifndef BANGUN_H
#define BANGUN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Bangun: public Command {
    public:
        Bangun(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif