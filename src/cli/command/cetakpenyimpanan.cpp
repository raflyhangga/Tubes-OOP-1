#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/grid/griddrawer.hpp>
#include <iostream>

using namespace std;
CetakPenyimpanan::CetakPenyimpanan(State &state) : Command(state) {}

void CetakPenyimpanan::execute(Petani *petani) {
    printInventory(petani); 
}
void CetakPenyimpanan::execute(Peternak *peternak) {
    printInventory(peternak); 
}
void CetakPenyimpanan::execute(Walikota *walikota) {
    printInventory(walikota); 
}


void CetakPenyimpanan::printInventory(Player *player){
    Grid<Resource*> inventory = player->getInventory();
    int total_length = inventory.getCol()*6 + 1;
    string message = " Penyimpanan ";
    string pad = string((total_length - message.length()) / 2 - 1, '=');
    cout << "   " <<  pad << '[' << message << ']' <<pad << endl;

    GridDrawerCLI<Resource*> drawer = GridDrawerCLI<Resource*>(inventory);
    drawer.draw();

    cout << "\nTotal slot kosong: " << inventory.getCountFilled() << "\n\n";
}


