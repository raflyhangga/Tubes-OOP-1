#ifndef NEXT_HPP
#define NEXT_HPP

#include <tubesoop1/cli/command/command.hpp>
#include <tubesoop1/player/player.h>

class Next: public Command {
    public:
        Next(Player &player);
        void execute();
};

#endif