#include <tubesoop1/gui/command/beli.h>
#include <tubesoop1/gui/command/cetakpenyimpanan.h>
#include <tubesoop1/shop/shop_exception.h>
#include <limits>
#include <tubesoop1/gui/command/tanam.h>
#include <tubesoop1/gui/command/command_exception.h>
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include <tubesoop1/grid/griddrawer.hpp>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/gui/components/dialog.h>
#include <tubesoop1/gui/components/inputdialog.h>
#include <tubesoop1/gui/components/choicedialog.h>
#include <QVBoxLayout>
#include <QLabel>
#include "tubesoop1/gui/components/gridview.hpp"

using namespace std;

Beli::Beli(State &state, MainWindow& window) : Command(state, window), shop(state.getShop()) {
    
}

bool Beli::isBuyable(pair<Quantifiable<Resource*>,bool> pair){
    return pair.second;
}

void Beli::validityChecking(vector<pair<Quantifiable<Resource*>,bool>> stock, Player* p,int idxItem,int quantity){
    // input index item 0 or negative
    if (idxItem < 0 || idxItem > shop.getstock().size())
    {
        throw out_of_range("Indeks barang tidak valid"); // Should be impossible because its handled by GUI
    }
    // input quantity more than stock
    if (quantity > shop.getstock()[idxItem].getQuantity())
    {
        throw out_of_range("Jumlah barang tidak valid");
    }
    // player money less than price
    if (p->getMoney() < shop.getstock()[idxItem].getValue()->getPrice() * quantity)
    {
        throw out_of_range("Uang tidak cukup");
    }
}

QVector<pair<string, string>> Beli::getChoices(vector<pair<Quantifiable<Resource*>,bool>>& stockList){
    QVector<pair<string, string>> choices;
    for (auto stock: stockList) {
        if(!stock.second) continue;

        string productName = stock.first.getValue()->getName();
        int productPrice = stock.first.getValue()->getPrice();
        string info = "Price: " + to_string(productPrice);
        if(!stock.first.isInfinite()){
            info += ", Stock: " + to_string(stock.first.getQuantity());
        }
        choices.append(pair<string, string>(formatName(productName), info));
    }
    return choices;
}


void Beli::handleCurrentPlayer(Player *player, vector<pair<Quantifiable<Resource*>,bool>> &stockList, function<void(int, int)> onBuyValid){
    QVector<pair<string, string>> choices = getChoices(stockList);

    ChoiceDialog choiceDialog = ChoiceDialog(&window, choices, "Beli", QString::fromStdString("Selamat datang di toko!\nBerikut merupakan hal yang dapat Anda Beli"), QString::fromStdString("Uang Anda: " + to_string(player->getMoney()) + "\nSlot penyimpanan tersedia: " + to_string(player->getInventory().getCountNotFilled())) );

    choiceDialog.connect(&choiceDialog, &ChoiceDialog::choiceMade, [&](int choosenIndex){
        if(stockList[choosenIndex].first.getQuantity() == 0) {
            MessageBox(&window, "Beli", "Stok barang yang dipilih sedang kosong!").exec(); return;
        }
        

        // Ask for quantity
        bool ok = false;
        int quantityToBuy;
        while(!ok){
            quantityToBuy = InputDialog::getInt(
                                                &window, 
                                                QString::fromStdString("Beli"),
                                                QString::fromStdString("Berapa yang ingin dibeli: "), 1, numeric_limits<int>::min(), numeric_limits<int>::max(), 1, &ok
                                        );
            if(!ok) return; // user clicked cancel or close
            try{
                validityChecking(stockList, player, choosenIndex, quantityToBuy);
                if(!isBuyable(stockList[choosenIndex])){
                    MessageBox(&window, "Beli", "Anda tidak bisa membeli barang ini!").exec();
                }
                ok = true;
            } catch (exception &e){
                MessageBox(&window, "Beli", e.what()).exec();
                ok = false;
            }
        }



        choiceDialog.close();

        MessageBox(&window, "Beli", "Anda berhasil membeli " + to_string(quantityToBuy) + " " + formatName(stockList[choosenIndex].first.getValue()->getName()) + ". Uang Anda tersisa " + to_string(player->getMoney()) + " gulden.").exec();

        Dialog dialogInventory(&window); dialogInventory.setClosable(false);
        QVBoxLayout vLayout;
        dialogInventory.setLayout(&vLayout); dialogInventory.setWindowTitle("Beli");
        QLabel label("Pilih slot untuk menyimpan barang yang Anda beli!");
        QLabel gridTitle("Penyimpanan"); gridTitle.setAlignment(Qt::AlignCenter);
        vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

        GridView<Resource*> inventoryButtonGrid;
        inventoryButtonGrid.setMinimumSize(QSize(960, 540));
        inventoryButtonGrid.setGrid(&player->getInventory());
        inventoryButtonGrid.setEnabled(true);
        vLayout.addWidget(&inventoryButtonGrid);
        QLabel locationListLabel;
        vLayout.addWidget(&locationListLabel);

        // // Choose the locations
        inventoryButtonGrid.setEnabled(true);
        inventoryButtonGrid.setCheckable(true);
        vector<Location> locationList;
        inventoryButtonGrid.connect(&inventoryButtonGrid, &GridView<Resource*>::cellClicked, [&](Location slot) {
            if(player->getInventory().isElementFilled(slot)){
                MessageBox(&dialogInventory, "Beli", "Petak yang dipilih sudah terisi!").exec();
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
            locationListLabel.setText(locationListText);

            // if done
            if(locationList.size() == quantityToBuy) {
                Resource *r = stockList[choosenIndex].first.getValue();
                string name = r->getName();
                onBuyValid(choosenIndex, quantityToBuy);
                for(Location l : locationList){
                    Resource *copy = state.translate(name);
                    player->putInventoryAt(*copy, l);
                }
                player->setMoney(player->getMoney() - stockList[choosenIndex].first.getValue()->getPrice() * quantityToBuy);
                inventoryButtonGrid.refresh();
                MessageBox(&dialogInventory, "Beli",  formatName(name) + " berhasil disimpan dalam penyimpanan!").exec();
                dialogInventory.accept();
            }
        });
        dialogInventory.exec();
    });
    choiceDialog.exec();
}

void Beli::execute(Petani *petani){
    vector<std::pair<Quantifiable<Resource *>, bool>> stockList = shop.getStock(petani);
    handleCurrentPlayer(petani, stockList, [&](int idxItem, int quantity){
        shop.buy(petani, idxItem, quantity);
    });
}

void Beli::execute(Peternak *peternak){
    vector<std::pair<Quantifiable<Resource *>, bool>> stockList = shop.getStock(peternak);
    handleCurrentPlayer(peternak, stockList, [&](int idxItem, int quantity){
        shop.buy(peternak, idxItem, quantity);
    });
}

void Beli::execute(Walikota *walikota){
    vector<std::pair<Quantifiable<Resource *>, bool>> stockList = shop.getStock(walikota);
    handleCurrentPlayer(walikota, stockList, [&](int idxItem, int quantity){
        shop.buy(walikota, idxItem, quantity);
    });
}