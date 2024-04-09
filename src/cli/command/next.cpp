#include <tubesoop1/cli/command/next.h>
#include <iostream>

using namespace std;

Next::Next(State &state) : Command(state) {}

void Next::execute(Petani *petani) {
    petani->addAllPlantAge(state.getTotalPlayer());
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();

    turnInfo();
}
void Next::execute(Peternak *peternak) {
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();

    turnInfo();
}
void Next::execute(Walikota *walikota) {
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();

    turnInfo();
}

void Next::turnInfo() {
    int numberOfPlayers = state.getTotalPlayer();
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player *player = state.getPlayer(i);
        cout << i + 1 << ". " << player->getUsername();
        if (state.getTurn() == i) cout << " (giliranmu)";
        cout << endl;
    }
}

