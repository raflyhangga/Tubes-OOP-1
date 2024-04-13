#include <tubesoop1/cli/command/next.h>
#include <iostream>

using namespace std;

Next::Next(State &state) : Command(state) {}

void Next::execute(Petani *petani) {
    Petani::incrementAllPlantAge();
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();

    turnInfo();
}
void Next::execute(Peternak *peternak) {
    Petani::incrementAllPlantAge();
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();

    turnInfo();
}
void Next::execute(Walikota *walikota) {
    Petani::incrementAllPlantAge();
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

