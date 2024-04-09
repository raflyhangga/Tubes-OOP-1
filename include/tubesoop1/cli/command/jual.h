#ifndef JUAL_H
#define JUAL_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Jual: public Command {
    public:
        Jual(State&);
        // visitor pattern
        void execute(Player*);
};

#endif