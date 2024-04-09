#include <tubesoop1/cli/command/jual.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <iostream>

using namespace std;

Jual::Jual(State &state) : Command(state) {}

void Jual::execute(Player *player) {
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    CetakPenyimpanan(state).print(player->getInventory());
}