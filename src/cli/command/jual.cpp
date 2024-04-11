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
    Grid<Resource*> &inventory = player->getInventory(); // DO

    CetakPenyimpanan(state).print(player->getInventory());

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    cout << "(Format: <Lokasi1>, <Lokasi2>, ...)" << endl;
    cout << "(Contoh: A01, A02)" << endl;
    cout << "Petak : ";

    string line; cin.ignore(); getline(cin, line); 
    vector<Location> ansLoc = inputListLocation(line);
    int addedMoney = 0;

    // Check any errors
    for(Location l : ansLoc){
        Resource *r = inventory[l];
    }

    // pop the resource and add the price
    for(Location l : ansLoc){
        Resource *r = inventory.pop(l);
        addedMoney += r->getPrice();
        state.addShopItem(Quantifiable<Resource*>(r, 1));
    }

    player->addMoney(addedMoney);
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << addedMoney << " gulden!\n\n";
}
