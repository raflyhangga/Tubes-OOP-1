#include <tubesoop1/gui/command/panen.h>
#include <tubesoop1/gui/command/cetakpeternakan.h>
#include <tubesoop1/gui/command/cetakladang.h>
#include <tubesoop1/gui/command/command_exception.h>
#include <tubesoop1/quantifiable/quantifiable.hpp>
#include <tubesoop1/grid/grid.hpp>
#include <iostream>
#include <vector>
#include "tubesoop1/gui/components/dialog.h"
#include "tubesoop1/gui/components/messagebox.h"
#include "tubesoop1/gui/components/choicedialog.h"
#include "tubesoop1/gui/components/inputdialog.h"
#include <set>
#include <algorithm>

using namespace std;

Panen::Panen(State &state, MainWindow& window) : Command(state, window) {}

void Panen::execute(Petani *petani) {
    vector<Quantifiable<Plant *>>* allHarvestablePlant = petani->getAllHarvestablePlant();
    if(allHarvestablePlant->size() == 0) {
        MessageBox(&window, "Panen", "Tidak ada tanaman yang siap dipanen!").exec(); return;
    }

    Dialog dialogInventory(&window);

    QVBoxLayout vLayout;
    dialogInventory.setLayout(&vLayout); dialogInventory.setWindowTitle("Panen");
    QLabel label("Pilih tanaman untuk dipanen");
    QLabel gridTitle("Ladang"); gridTitle.setAlignment(Qt::AlignCenter);
    vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

    GridView<Plant*> ladangButtonGrid;
    ladangButtonGrid.setMinimumSize(QSize(960, 540));
    ladangButtonGrid.setGrid(&petani->getLadang());
    vLayout.addWidget(&ladangButtonGrid);
    
    QLabel infoLabel; infoLabel.setText(QString::fromStdString(
        CetakLadang(state, window).getInfo(petani->getLadang())
    ));
    vLayout.addWidget(&infoLabel);
    QLabel panenLocationListLabel; panenLocationListLabel.setText("Pilihan petak untuk dipanen: \n");

    QVector<pair<string, string>> choices;
    vector<string> indexedKeys;

    for(int i = 0; i < allHarvestablePlant->size(); i++) {
        // pop the element if the quantity is 0
        while((*allHarvestablePlant)[i].getQuantity() == 0) {
            allHarvestablePlant->erase(allHarvestablePlant->begin() + i);
        }
        choices.append(pair<string, string>(
            (*allHarvestablePlant)[i].getValue()->getName() + " (" + (*allHarvestablePlant)[i].getValue()->getCode() + ")",
            to_string((*allHarvestablePlant)[i].getQuantity()) + " petak siap panen"
        ));
    }
    ChoiceDialog choiceDialog = ChoiceDialog(&dialogInventory, choices, "Panen", "Daftar Tanaman siap panen", "Pilih tanaman yang ingin dipanen");

    choiceDialog.connect(&choiceDialog, &ChoiceDialog::choiceMade, [&](int chosenPlantIdx){
        string chosenPlantCode = (*allHarvestablePlant)[chosenPlantIdx].getValue()->getCode();
        int harvestableAmount = (*allHarvestablePlant)[chosenPlantIdx].getQuantity();
        int inventoryCapacity = petani->getInventory().getCountNotFilled();
        // Ask for the amount of square to harvest
        bool ok = false;
        int amountOfSquareToHarvest;
        while(!ok){
            amountOfSquareToHarvest = InputDialog::getInt(
                                                &window, 
                                                QString::fromStdString("Panen"),
                                                QString::fromStdString("Berapa petak yang ingin dipanen: "), 1, numeric_limits<int>::min(), numeric_limits<int>::max(), 1, &ok
                                        );
            if(amountOfSquareToHarvest < 1) {
                MessageBox(&window, "Panen", "Jumlah petak yang ingin dipanen tidak boleh kurang dari 1!").exec(); 
                ok = false; continue;
            }
            if(amountOfSquareToHarvest > harvestableAmount){
                MessageBox(&window, "Panen", "Jumlah petak yang ingin dipanen tidak boleh lebih dari jumlah tanaman yang dimiliki!\nJumlah tanaman yang dimiliki: " + to_string(harvestableAmount) + "\n").exec();
                ok = false; continue;
            }
            if(amountOfSquareToHarvest > inventoryCapacity) {
                MessageBox(&window, "Panen", "Jumlah petak yang ingin dipanen tidak boleh lebih dari kapasitas penyimpanan!\nKapasitas penyimpanan: " + to_string(inventoryCapacity) + "\n").exec(); return;
                ok = false; continue;
            }
        }
        choiceDialog.close();
        

        // Choose the locations
        ladangButtonGrid.setEnabled(true);
        ladangButtonGrid.setCheckable(true);
        vector<Location> locationList;
        ladangButtonGrid.connect(&ladangButtonGrid, &GridView<Resource*>::cellClicked, [&](Location slot) {
            
            Plant *chosenPlant = petani->getLadang()[slot];
            
            // Check if different plant than the chosen one
            if(chosenPlantCode != chosenPlant->getCode()) {
                MessageBox(&window, "Panen", "Tanaman yang dipilih tidak sesuai.\nSeharusnya: " + chosenPlantCode + "\nDitemukan: " + chosenPlant->getCode()).exec(); return;
            }

            // if the slot is already in the list, remove it, otherwise add it
            if(find(locationList.begin(), locationList.end(), slot) != locationList.end()) {
                locationList.erase(remove(locationList.begin(), locationList.end(), slot), locationList.end());
            } else {
                locationList.push_back(slot);
            }
            // update the label
            QString locationListText = "Pilihan petak untuk dipanen: \n";
            for(int i = 0; i < locationList.size(); i++){
                locationListText += QString::fromStdString("Petak ke-" + to_string(i) + ": " + slot.toStdString()) + "\n";
            }
            panenLocationListLabel.setText(locationListText);

            // if done
            if(locationList.size() == amountOfSquareToHarvest) {
                // pop the plant and put the result to inventory
                for(const auto &loc : locationList) {
                    Plant* p = petani->getLadang().pop(loc);
                    vector<Product *>& drops = p->harvest();
                    for(Product *product : drops) {
                        petani->putInventory(*product);
                    }
                }
                string message = to_string(locationList.size()) + " petak tanaman " + chosenPlant->getCode() + " pada petak " + locationList[0].toStdString();
                for(int i = 1; i < locationList.size(); i++) {
                    message += ", " + locationList[i].toStdString();
                }
                message += " telah dipanen!";

                ladangButtonGrid.refresh();
                MessageBox(&window, "Panen", message).exec();

                delete allHarvestablePlant; 
            }
        });

        dialogInventory.exec();
    });
    dialogInventory.show(); // only show, will exec later
    choiceDialog.exec();
}
void Panen::execute(Peternak *peternak) {
    
}
void Panen::execute(Walikota *walikota) {
    MessageBox(&window, "Panen", "Walikota tidak bisa melakukan panen!").exec();
}


