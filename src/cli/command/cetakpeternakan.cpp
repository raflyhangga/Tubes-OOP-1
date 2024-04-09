#include <tubesoop1/cli/command/cetakpeternakan.h>
#include <tubesoop1/cli/command/command_exception.h>
#include <tubesoop1/grid/griddrawer.hpp>

#include <iostream>
#include <set>

using namespace std;

CetakPeternakan::CetakPeternakan(State &state) : Command(state) {}

void CetakPeternakan::execute(Peternak *peternak) {

    GridDrawerCLI<Animal*> drawer = GridDrawerCLI<Animal*>(peternak->getPeternakan());

    Grid<Animal *> peternakan = peternak->getPeternakan();

    // print grid
    int total_length = peternakan.getCol()*6 + 1;
    string message = " Peternakan ";
    string pad = string((total_length - message.length()) / 2 - 1, '=');
    cout << "   " <<  pad << '[' << message << ']' <<pad << endl;
    drawer.draw();

    set<pair<string, string>> codesAndNames;
    for (const auto &loc: peternakan) {
        Animal *animal = peternakan.getElement(loc);
        codesAndNames.insert({animal->getCode(), animal->getName()});
    }

    for (auto &[code, name]: codesAndNames) {
        cout << "- " << code << ": " << name << '\n';
    }
    cout << '\n';
}
void CetakPeternakan::execute(Petani *petani) {
    throw CommandNotAllowedException("CETAK_LADANG");
}
void CetakPeternakan::execute(Walikota *walikota) {
    throw CommandNotAllowedException("CETAK_LADANG");
}

