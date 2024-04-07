#ifndef CETAKPENYIMPANAN_HPP
#define CETAKPENYIMPANAN_HPP

#include <tubesoop1/cli/command/command.hpp>
#include <tubesoop1/player/player.h>

class CetakPenyimpanan: public Command {
    public:
        void printInventory(Player *player);
        void execute(Player *player);
};

#endif