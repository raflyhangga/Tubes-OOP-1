#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <tubesoop1/player/player.h>
using namespace std;

class Command {
    public:
        virtual void execute(Player *player) = 0;
};



#endif