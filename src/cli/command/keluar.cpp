#include <tubesoop1/cli/command/keluar.h>
#include <iostream>

using namespace std;
Keluar::Keluar(State &state) : Command(state) {}

void Keluar::execute(Player *player) {
    exit(0);
}
