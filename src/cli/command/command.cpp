#include <tubesoop1/cli/command/command.h>

Command::Command(State &state) : state(state) {}

void Command::execute(PlayerElement *player) {
    player->executed(*this);
}