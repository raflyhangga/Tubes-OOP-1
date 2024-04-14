#include "tubesoop1/gui/command/kasihmakan.h"
#include "tubesoop1/gui/command/command_exception.h"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include "tubesoop1/grid/location_exception.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/product/product.h"
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/gui/components/dialog.h>

KasihMakan::KasihMakan(State& state, MainWindow& window): Command(state, window) {}


void KasihMakan::execute(Petani* petani) {
    MessageBox(&window, "Kasih Makan", "Petani tidak bisa memberi makan hewan!").exec();
}

void KasihMakan::execute(Walikota* walkot){
    MessageBox(&window, "Kasih Makan", "Walikota tidak bisa memberi makan hewan!").exec();
}

void KasihMakan::execute(Peternak* peternak){
    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();
    Player *player = state.getCurrentPlayer();
    if(peternak->getPeternakan().getCountFilled() == 0){
        MessageBox(&window, "Kasih Makan", "Tidak ada hewan di peternakan!").exec(); return;
    }
    
    Dialog dialogPeternakan(&window);

    QVBoxLayout vLayout;
    dialogPeternakan.setLayout(&vLayout); dialogPeternakan.setWindowTitle("Kasih Makan");
    QLabel label("Pilih petak kandang yang akan diletakkan makanan");
    QLabel gridTitle("Peternakan"); gridTitle.setAlignment(Qt::AlignCenter);
    vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

    GridView<Animal*> peternakanButtonGrid;
    peternakanButtonGrid.setMinimumSize(QSize(960, 540));
    peternakanButtonGrid.setGrid(&peternak->getPeternakan());
    peternakanButtonGrid.setEnabled(true);
    vLayout.addWidget(&peternakanButtonGrid);

    peternakanButtonGrid.connect(&peternakanButtonGrid, &GridView<Animal*>::cellClicked, [this, &peternak, &dialogPeternakan](Location slot) {
        Animal *animal = peternak->getPeternakan()[slot];

        // Check if there's no food that can be given to the animal
        vector<Product*> productList = peternak->takeAllFromInventory<Product>();
        // If there exist a product that can be given to the animal, then the player can give food to the animal
        bool canEat = false;
        for(Product* product : productList){
            try{
                animal->eat(*product);
                animal->setWeight(animal->getWeight() - product->getAddedWeight());
                canEat = true;
                break;
            } catch (CannotEatException &e) {
            }
        }
        if(!canEat){
            MessageBox(&window, "Kasih Makan", "Makanan yang bisa diberikan kepada "+formatName(animal->getName())+" tidak tersedia!").exec();
            return;
        }

        dialogPeternakan.close();

        // // print label and grid ladang
        Dialog dialogInventory(&window); dialogInventory.setWindowTitle("Kasih Makan");

        QVBoxLayout vLayout;
        dialogInventory.setLayout(&vLayout);
        QLabel label("Kamu memilih sapi untuk diberi makan.\nPilih pangan yang akan diberikan:");
        QLabel gridTitle("Penyimpanan"); gridTitle.setAlignment(Qt::AlignCenter);
        vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

        GridView<Resource*> inventoryButtonGrid;
        inventoryButtonGrid.setMinimumSize(QSize(960, 540));
        inventoryButtonGrid.setGrid(&peternak->getInventory());
        inventoryButtonGrid.setEnabled(true);
        vLayout.addWidget(&inventoryButtonGrid);

        inventoryButtonGrid.connect(&inventoryButtonGrid, &GridView<Resource*>::cellClicked, [this, &peternak, &animal, &slot, &dialogInventory, &inventoryButtonGrid](Location loc) {

            try {
                Product* product = peternak->takeInventory<Product>(loc);
                animal->eat(*product);
            } catch (NotTakableException &e) {
                MessageBox(&window, "Kasih Makan", "Benda tersebut tidak dapat dimakan oleh hewan!").exec(); return;
            } catch (exception &e) {
                MessageBox(&window, "Kasih Makan", e.what()).exec(); return;
            }


            peternak->getInventory().pop(loc);
            inventoryButtonGrid.refresh();
            MessageBox(&window, "Kasih Makan", "Hewan telah diberi makan!\nBeratnya menjadi " + to_string(animal->getWeight()) + ".").exec();

            dialogInventory.close();
        });
        
        dialogInventory.exec();
    });

    dialogPeternakan.exec();

}
