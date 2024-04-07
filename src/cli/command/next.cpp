#include <tubesoop1/cli/command/next.hpp>
#include <tubesoop1/cli/globals.hpp>
#include <iostream>

using namespace std;

void Next::execute(Player *player) {
    // TODO: Umur tanamah bertambah 1.


    Globals::turn = (Globals::turn + 1) % Globals::players.size();
    cout << "Giliran " << Globals::players[Globals::turn]->getUsername() << " yang bermain.\n";
}

