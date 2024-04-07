#include <tubesoop1/cli/command/cetakpenyimpanan.hpp>
#include <tubesoop1/grid/griddrawer.hpp>
#include <iostream>

using namespace std;

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

void CetakPenyimpanan::execute(Player *player) {
    printInventory(player); 
}

