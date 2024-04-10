#ifndef TANAM_H
#define TANAM_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Tanam: public Command {
    public:
        Tanam(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif