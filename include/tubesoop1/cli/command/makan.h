#ifndef MAKAN_H
#define MAKAN_H

#include "tubesoop1/cli/command/command.h"

class Makan: public Command {
    public:
        Makan(State&);
        // visitor pattern
        void execute(Player*);
};

#endif