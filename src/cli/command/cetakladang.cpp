#include <tubesoop1/cli/command/cetakladang.h>
#include <tubesoop1/cli/command/command_exception.h>
#include <tubesoop1/grid/griddrawer.hpp>

#include <iostream>
#include <set>

using namespace std;

CetakLadang::CetakLadang(State &state) : Command(state) {}

void CetakLadang::execute(Petani *petani) {
    GridDrawerCLI<Plant*> drawer = GridDrawerCLI<Plant*>(petani->getLadang());

    Grid<Plant *> ladang = petani->getLadang();

    printLabelAndGrid(petani, ladang);

    set<pair<string, string>> codesAndNames;
    for (const auto &loc: ladang) {
        Plant *plant = ladang.getElement(loc);
        codesAndNames.insert({plant->getCode(), plant->getName()});
    }

    for (auto &[code, name]: codesAndNames) {
        cout << "- " << code << ": " << name << '\n';
    }
    cout << '\n';
}
void CetakLadang::execute(Peternak *peternak) {
    throw CommandNotAllowedException("CETAK_LADANG");
}
void CetakLadang::execute(Walikota *walikota) {
    throw CommandNotAllowedException("CETAK_LADANG");
}

void CetakLadang::printLabelAndGrid(Petani *petani, Grid<Plant *> &ladang) {
    GridDrawerCLI<Plant*> drawer = GridDrawerCLI<Plant*>(petani->getLadang());
    int total_length = ladang.getCol()*6 + 1;
    string message = " Ladang ";
    string pad = string((total_length - message.length()) / 2 - 1, '=');
    cout << "   " <<  pad << '[' << message << ']' << pad << endl;
    drawer.draw();
}
