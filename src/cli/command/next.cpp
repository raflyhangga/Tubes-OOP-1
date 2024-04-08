#include <tubesoop1/cli/command/next.h>
#include <iostream>

using namespace std;

Next::Next(State &state) : Command(state) {}

void Next::execute(Petani *petani) {
    petani->incrementAllPlantAge();
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();
}
void Next::execute(Peternak *peternak) {
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();
}
void Next::execute(Walikota *walikota) {
    cout << "Giliran dilanjut ke pemain berikutnya." << endl;
    state.nextTurn();
}

