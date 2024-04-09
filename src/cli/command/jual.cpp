#include <tubesoop1/cli/command/jual.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/grid/grid.hpp>
#include <vector>
#include <iostream>

using namespace std;

Jual::Jual(State &state) : Command(state) {}

void Jual::execute(Player *player) {
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    Grid<Resource*> inventory = player->getInventory();
    CetakPenyimpanan(state).print(player->getInventory());

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    cout << "Petak : ";
    int i = 0;
    for(Location l : inventory){
        if(i == 0)cout << l;
        else cout << ", " << l;
    }
    vector<Location> ansLoc;

    cout << "Barang Anda berhasil dijual! Uang Anda bertambah 12 gulden!\n\n";
}