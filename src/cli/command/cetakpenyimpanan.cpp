#include <tubesoop1/cli/command/cetakpenyimpanan.hpp>
#include <iostream>

using namespace std;

void CetakPenyimpanan::execute(Player *player) {
    player->printInventory();
}

