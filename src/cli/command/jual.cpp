#include <tubesoop1/cli/command/jual.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/grid/grid.hpp>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

Jual::Jual(State &state) : Command(state) {}


void Jual::execute(Petani* p){
    Grid<Resource*> &inventory = p->getInventory();
    vector<Location> ansLoc = promptChoosenLocation(p); // Will throw error if the location is not valid

    vector<Building*> buildingList = p->takeAllFromInventory<Building>();

    // throw error if there is any building in ansLoc
    for(Location l : ansLoc){
        for(Building* b : buildingList){
            if(inventory[l] == b) throw invalid_argument("Tidak bisa menjual bangunan!");
        }
    }
    
    popAndAddMoneyFromInventory(p, ansLoc);
}

void Jual::execute(Peternak* p){
    Grid<Resource*> &inventory = p->getInventory();
    vector<Location> ansLoc = promptChoosenLocation(p); // Will throw error if the location is not valid
    vector<Building*> buildingList = p->takeAllFromInventory<Building>();

    // throw error if there is any building in ansLoc
    for(Location l : ansLoc){
        for(Building* b : buildingList){
            if(inventory[l] == b) throw invalid_argument("Tidak bisa menjual bangunan!");
        }
    }

    popAndAddMoneyFromInventory(p, ansLoc);
}

void Jual::execute(Walikota* p){
    Grid<Resource*> &inventory = p->getInventory();
    vector<Location> ansLoc = promptChoosenLocation(p); // Will throw error if the location is not valid
    popAndAddMoneyFromInventory(p, ansLoc);
}


void Jual::popAndAddMoneyFromInventory(Player* p, vector<Location>& ansLoc){
    Grid<Resource*> &inventory = p->getInventory();
    // pop the resource and add the price
    int addedMoney = 0;
    for(Location l : ansLoc){
        Resource *r = inventory.pop(l);
        addedMoney += r->getPrice();
        state.addShopItem(Quantifiable<Resource*>(r, 1));
    }

    p->addMoney(addedMoney);
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << addedMoney << " gulden!\n\n";
}

vector<Location> Jual::promptChoosenLocation(Player *player) {
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    Grid<Resource*> &inventory = player->getInventory(); // DO

    CetakPenyimpanan(state).print(player->getInventory());

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    cout << "(Format: <Lokasi1>, <Lokasi2>, ...)" << endl;
    cout << "(Contoh: A01, A02)" << endl;
    cout << "Petak : ";

    string line; cin.ignore(); getline(cin, line); 
    vector<Location> ansLoc = inputListLocation(line);

    // Check any errors
    for(Location l : ansLoc){
        Resource *r = inventory[l];
    }

    return ansLoc;
}