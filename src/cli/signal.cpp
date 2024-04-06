#include <iostream>
#include <tubesoop1/cli/signal.hpp>

using namespace std;

GameOverSignal::GameOverSignal(string name) {
    winnersName = name;
}

void GameOverSignal::announce() {
    cout << "Grats! Game over! This Game winner is " << winnersName << '\n';
}