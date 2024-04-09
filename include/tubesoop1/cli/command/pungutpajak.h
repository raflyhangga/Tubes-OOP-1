#ifndef PUNGUTPAJAK_H
#define PUNGUTPAJAK_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class PungutPajak: public Command {
    public:
        PungutPajak(State&);
        // visitor pattern
        void execute(Petani*);
        void execute(Peternak*);
        void execute(Walikota*);
};

#endif