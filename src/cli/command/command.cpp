#include <tubesoop1/cli/command/command.h>

Command::Command(State &state) : state(state) {}

void Command::execute(Player *player) {
    player->executed(*this);
}

void Command::execute(Petani *petani) {}
void Command::execute(Peternak *peternak) {}
void Command::execute(Walikota *walikota) {}