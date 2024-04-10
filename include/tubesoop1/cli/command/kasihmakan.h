#ifndef KASIHMAKAN_H
#define KASIHMAKAN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class KasihMakan: public Command {

    public:
        KasihMakan(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif