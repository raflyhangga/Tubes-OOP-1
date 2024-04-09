#include <tubesoop1/cli/command/jual.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/grid/grid.hpp>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

Jual::Jual(State &state) : Command(state) {}

void Jual::execute(Player *player) {
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    Grid<Resource*> inventory = player->getInventory();
    CetakPenyimpanan(state).print(player->getInventory());

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    cout << "(Format: <Lokasi1>, <Lokasi2>, ...)" << endl;
    cout << "(Contoh: A01, A02)" << endl;
    cout << "Petak : ";

    string line; cin.ignore(); getline(cin, line); 
    vector<Location> ansLoc = inputListLocation(line);
    for(Location l : ansLoc){
        cout << l << endl;
    }
    int addedMoney = 0;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << addedMoney << " gulden!\n\n";
}
