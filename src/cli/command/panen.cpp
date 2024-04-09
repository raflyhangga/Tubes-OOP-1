#include <tubesoop1/cli/command/panen.h>
#include <tubesoop1/cli/command/cetakpeternakan.h>
#include <tubesoop1/cli/command/cetakladang.h>
#include <tubesoop1/cli/command/command_exception.h>
#include <tubesoop1/quantifiable/quantifiable.h>
#include <iostream>

using namespace std;

Panen::Panen(State &state) : Command(state) {}

void Panen::execute(Petani *petani) {
    Grid<Plant*> &ladang = petani->getLadang();
    CetakLadang(state).print(ladang);
    vector<Quantifiable<Plant *>>* allHarvestablePlant = petani->getAllHarvestablePlant();
    for(Quantifiable<Plant *> &v : *allHarvestablePlant) {
        cout << " - " << v.getValue()->getCode()
        << ": " << v.getValue()->getName() << endl;
    }

    cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
    for(int i = 0; i < allHarvestablePlant->size(); i++) {
        while((*allHarvestablePlant)[i].getQuantity() == 0) {
            // pop the element
            allHarvestablePlant->erase(allHarvestablePlant->begin() + i);
        }
        cout << " " << i+1 << ". " << (*allHarvestablePlant)[i].getValue()->getCode()
        << ": " << (*allHarvestablePlant)[i].getValue()->getName() << endl;
    }

    int chosenPlantIdx;
    cout << "Nomor tanaman yang ingin dipanen: " << endl << endl;
    cin >> chosenPlantIdx;
    if(chosenPlantIdx > allHarvestablePlant->size() || chosenPlantIdx < 1) 
        throw out_of_range("Index di luar batas.");

    int amountOfSquareToHarvest;
    cout << "Berapa petak yang ingin dipanen: " << endl << endl;

    cin >> amountOfSquareToHarvest;
    if(amountOfSquareToHarvest < 1) 
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh kurang dari 1.");
    if(amountOfSquareToHarvest > (*allHarvestablePlant)[chosenPlantIdx-1].getQuantity()){
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh lebih dari jumlah tanaman yang dimiliki! Jumlah tanaman yang dimiliki: " + to_string((*allHarvestablePlant)[chosenPlantIdx-1].getQuantity()) + "\n");
    }

    int notFilledAmount = ladang.getCountNotFilled();
    if(amountOfSquareToHarvest > notFilledAmount) {
        throw out_of_range("Jumlah penyimpanan tidak cukup!\nJumlah penyimpanan yang tidak terisi: " + to_string(notFilledAmount));
    }

    cout << "Pilih petak yang ingin dipanen:" << endl;

    Plant *chosenPlant = (*allHarvestablePlant)[chosenPlantIdx-1].getValue();
    vector<Location> chosenPlantLocation;
    for(int i = 0; i < amountOfSquareToHarvest; i++){
        cout << "Petak ke-" << i+1 << ": ";
        Location l; cin >> l;
        if(ladang[l]->getCode() != chosenPlant->getCode()) {
            throw invalid_argument("Tanaman yang dipilih tidak sesuai.\n Seharusnya: " + chosenPlant->getCode() + "\nDitemukan: " + ladang[l]->getCode());
        }
        chosenPlantLocation.push_back(l);
    }
    cout << chosenPlantLocation.size() << " petak tanaman " << chosenPlant->getCode() << " pada petak ";
    cout << chosenPlantLocation[0];
    for(int i = 1; i < chosenPlantLocation.size(); i++) {
        cout << ", " << chosenPlantLocation[i];
    }
    cout << " telah dipanen!" << endl; 

    delete allHarvestablePlant;
}
void Panen::execute(Peternak *peternak) {
    Grid<Animal*> &peternakan = peternak->getPeternakan();
    // CetakPeternakan(state).print(peternakan);
    cout << "Pilih hewan siap panen yang kamu miliki." << endl;
}
void Panen::execute(Walikota *walikota) {
    throw CannotPanenException(*walikota);
}

