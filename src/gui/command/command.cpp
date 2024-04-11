#include <tubesoop1/gui/command/command.h>

Command::Command(MainWindow &state) : state(state) {}

void Command::execute(Player *player) {
    player->executed(*this);
}

void Command::execute(Petani *petani) {}
void Command::execute(Peternak *peternak) {}
void Command::execute(Walikota *walikota) {}
