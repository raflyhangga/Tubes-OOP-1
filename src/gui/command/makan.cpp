#include "tubesoop1/gui/command/makan.h"
#include "tubesoop1/gui/command/cetakpenyimpanan.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/animal/animal_exception.h"
#include "tubesoop1/grid/location_exception.h"

#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include <tubesoop1/gui/command/command_exception.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/gui/components/dialog.h>
Makan::Makan(State &state, MainWindow& window) : Command(state, window) {}

void Makan::execute(Player* player){
    if(player->getInventory().getCountFilled() == 0){
        MessageBox(&window, "Makan", "Penyimpanan kosong!").exec(); return;
    }

    // its fine if empty
    vector<ProductFruit*> fruitList = player->takeAllFromInventory<ProductFruit>();
    vector<ProductAnimal*> animalList = player->takeAllFromInventory<ProductAnimal>();
    
    // Combine the two lists
    vector<Product*> productList;
    productList.insert(productList.end(), fruitList.begin(), fruitList.end());

    if(productList.size() == 0){
        MessageBox(&window, "Makan", "Tidak ada makanan di penyimpanan!").exec(); return;
    }

    Dialog dialogInventory(&window);

    QVBoxLayout vLayout;
    dialogInventory.setLayout(&vLayout); dialogInventory.setWindowTitle("Makan");
    QLabel label("Pilih makanan dari penyimpanan");
    QLabel gridTitle("Penyimpanan"); gridTitle.setAlignment(Qt::AlignCenter);
    vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

    GridView<Resource*> inventoryButtonGrid;
    inventoryButtonGrid.setMinimumSize(QSize(960, 540));
    inventoryButtonGrid.setGrid(&player->getInventory());
    inventoryButtonGrid.setEnabled(true);
    vLayout.addWidget(&inventoryButtonGrid);

    inventoryButtonGrid.connect(&inventoryButtonGrid, &GridView<Resource*>::cellClicked, [this, &player, &dialogInventory, &productList, &inventoryButtonGrid](Location loc) {
        try{
            Product *food = player->takeInventory<Product>(loc);
            player->eat(*food);
            player->getInventory().pop(loc);
            inventoryButtonGrid.refresh();
            MessageBox(&dialogInventory, "Makan", "Kenyang gan, berat badan naik " + to_string(food->getAddedWeight()) + " kg jadi " + to_string(player->getWeight())).exec();
            dialogInventory.close();
        } catch (logic_error& e){
            MessageBox(&dialogInventory, "Makan", "Kamu mengambil harapan kosong dari penyimpanan.\nSilahkan masukan slot yang berisi makanan.").exec();
        } catch (NotTakableException& e){
            MessageBox(&dialogInventory, "Makan", "Apa yang kamu lakukan? Kamu mencoba untuk memakan itu? Silahkan masukan slot yang berisi makanan.").exec();
        } catch (CannotEatException& e){
            MessageBox(&dialogInventory, "Makan", "Keras, makanannya ga bisa digigit.").exec();
        } catch (exception& e){
            MessageBox(&dialogInventory, "Makan", e.what()).exec();
        }
        
    });
        
    
    dialogInventory.exec();
}