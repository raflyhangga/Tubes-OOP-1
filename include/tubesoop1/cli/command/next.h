#ifndef NEXT_H
#define NEXT_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Next: public Command {
    private:
        void turnInfo();

    public:
        Next(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif