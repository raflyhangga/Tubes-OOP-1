#include <tubesoop1/gui/command/command.h>

Command::Command(State& state, MainWindow& window) : state(state), window(window) {}

void Command::execute(Player *player) {
    player->executed(*this);
}

void Command::execute(Petani *petani) {}
void Command::execute(Peternak *peternak) {}
void Command::execute(Walikota *walikota) {}

string Command::formatName(string formattedName) {
    for (char &c : formattedName) {
        if (c == '_') c = ' ';
        else c = tolower(c);
    }
    formattedName[0] = toupper(formattedName[0]);
    return formattedName;
}