#include <tubesoop1/gui/command/jual.h>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/grid/grid.hpp>
#include <vector>

#include <tubesoop1/player/player_partial.hpp>
#include <tubesoop1/grid/griddrawer.hpp>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/gui/components/dialog.h>
#include <QVBoxLayout>
#include <QLabel>
#include "tubesoop1/gui/components/gridview.hpp"

using namespace std;

Jual::Jual(State &state, MainWindow &window) : Command(state, window) {}


void Jual::execute(Petani* p){
    Grid<Resource*> &inventory = p->getInventory();
    vector<Building*> buildingList = p->takeAllFromInventory<Building>();
    
    // validate that its not a building
    vector<Location> ansLoc = promptChoosenLocation(p, [&](Location l){
        // if the current selected location is a building, return false
        for(Building* b : buildingList){
            if(inventory[l] == b) {
                MessageBox(&window, "Jual", "Petani tidak bisa menjual bangunan!").exec();
                return false;
            }
        }
        return true;
    }); // Will throw error if the location is not valid
    
    popAndAddMoneyFromInventory(p, ansLoc);
}

void Jual::execute(Peternak* p){
    Grid<Resource*> &inventory = p->getInventory();
    vector<Building*> buildingList = p->takeAllFromInventory<Building>();
    
    // validate that its not a building
    vector<Location> ansLoc = promptChoosenLocation(p, [&](Location l){
        for(Building* b : buildingList){
            if(inventory[l] == b) {
                MessageBox(&window, "Jual", "Peternak tidak bisa menjual bangunan!").exec();
                return false;
            }
        }
        return true;
    }); // Will throw error if the location is not valid

    // throw error if there is any building in ansLoc

    popAndAddMoneyFromInventory(p, ansLoc);
}

void Jual::execute(Walikota* p){
    Grid<Resource*> &inventory = p->getInventory();
    vector<Location> ansLoc = promptChoosenLocation(p, [](Location l) { return true; }); // Will throw error if the location is not valid. Walikota can sell anything so the validator is always true
    popAndAddMoneyFromInventory(p, ansLoc);
}


void Jual::popAndAddMoneyFromInventory(Player* p, vector<Location>& ansLoc){
    // this means the player closes the dialog without choosing any location. Not an error, not confirming when no location is chosen.
    if(ansLoc.size() == 0) return;

    Grid<Resource*> &inventory = p->getInventory();
    // pop the resource and add the price
    int addedMoney = 0;
    for(Location l : ansLoc){
        Resource *r = inventory.pop(l);
        addedMoney += r->getPrice();
        state.addShopItem(Quantifiable<Resource*>(r, 1));
    }

    p->addMoney(addedMoney);
    MessageBox(&window, "Jual", "Barang Anda berhasil dijual! Uang Anda bertambah " + to_string(addedMoney) + " gulden!").exec();
}

vector<Location> Jual::promptChoosenLocation(Player *player, function<bool(Location)> validator) {
    Dialog dialogInventory(&window);
    QVBoxLayout vLayout;
    dialogInventory.setLayout(&vLayout); dialogInventory.setWindowTitle("Jual");
    QLabel label("Berikut merupakan penyimpanan Anda");
    QLabel gridTitle("Penyimpanan"); gridTitle.setAlignment(Qt::AlignCenter);
    vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

    GridView<Resource*> inventoryButtonGrid;
    inventoryButtonGrid.setMinimumSize(QSize(960, 540));
    inventoryButtonGrid.setGrid(&player->getInventory());
    inventoryButtonGrid.setEnabled(true);
    inventoryButtonGrid.setCheckable(true);
    vLayout.addWidget(&inventoryButtonGrid);

    QLabel labelBottom("Silahkan pilih petak yang ingin Anda jual!\nPetak (klik elemen grid di atas): ");
    vLayout.addWidget(&labelBottom);
    NiceButton confirmButton("Konfirmasi Jual");
    vLayout.addWidget(&confirmButton);

    vector<Location> locationList;
    inventoryButtonGrid.connect(&inventoryButtonGrid, &GridView<Resource*>::cellClicked, [&](Location slot) {
        if(!player->getInventory().isElementFilled(slot)){
            MessageBox(&dialogInventory, "Jual", "Petak yang dipilih kosong!").exec(); 
            inventoryButtonGrid.setButtonChecked(slot, false); return;
        }
        if(!validator(slot)){
            inventoryButtonGrid.setButtonChecked(slot, false); return;
        }

        // if the slot is already in the list, remove it, otherwise add it
        if(find(locationList.begin(), locationList.end(), slot) != locationList.end()) {
            locationList.erase(remove(locationList.begin(), locationList.end(), slot), locationList.end());
        } else {
            locationList.push_back(slot);
        }

        // update the label
        QString locationListText = "Pilihan petak (klik elemen grid di atas): \n";
        for(int i = 0; i < locationList.size(); i++){
            if(i == 0) locationListText += QString::fromStdString(locationList[i].toStdString());
            else locationListText += QString::fromStdString(", " + locationList[i].toStdString());
        }
        labelBottom.setText(locationListText);
    });
    dialogInventory.connect(&dialogInventory, &QDialog::rejected, [&]() {
        locationList.clear();
    });

    confirmButton.connect(&confirmButton, &NiceButton::clicked, [&](){
        if(locationList.size() == 0){
            MessageBox(&dialogInventory, "Jual", "Anda belum memilih petak untuk dijual!").exec(); return;
        }
        inventoryButtonGrid.refresh();
        dialogInventory.accept();
    });

    dialogInventory.exec();

    return locationList;
}