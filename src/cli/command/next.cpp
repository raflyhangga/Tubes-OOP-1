#include <tubesoop1/cli/command/next.h>
#include <iostream>

using namespace std;

Next::Next(State &state) : Command(state) {}

void Next::execute(Petani *petani) {
    cout << petani->getUsername() << endl;
    state.nextTurn();
}
void Next::execute(Peternak *peternak) {
    cout << peternak->getUsername() << endl;
    state.nextTurn();
}
void Next::execute(Walikota *walikota) {
    cout << walikota->getUsername() << endl;
    state.nextTurn();
}

