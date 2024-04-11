#ifndef STATUS_H
#define STATUS_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Status: public Command {
    public:
        Status(State&);
        // visitor pattern
        void execute(Peternak*);
        void execute(Petani*);
        void execute(Walikota*);
};

#endif