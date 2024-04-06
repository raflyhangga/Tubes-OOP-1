#include <tubesoop1/cli/command/next.hpp>
#include <iostream>

using namespace std;

Next::Next(Player *player) {
    this->player = player;
}

void Next::execute() {
    cout << "Next command executed" << endl;
}

