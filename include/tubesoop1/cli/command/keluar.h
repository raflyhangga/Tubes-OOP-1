#ifndef KELUAR_H
#define KELUAR_H

#include <tubesoop1/cli/command/command.h>

class Keluar: public Command {
    public:
        Keluar(State&);
        // visitor pattern
        void execute(Player*);
};

#endif