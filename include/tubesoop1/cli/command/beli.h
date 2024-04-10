#ifndef BANGUN_H
#define BANGUN_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>

class Beli: public Command {
    public:
        Beli(State&);
        // visitor pattern
        void execute(Player*);
};

#endif