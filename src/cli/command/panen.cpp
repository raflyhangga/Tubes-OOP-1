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
    CetakLadang printer(state);
    
    printer.printGrid(ladang);
    printer.printInfo(ladang);

    vector<Quantifiable<Plant *>>* allHarvestablePlant = petani->getAllHarvestablePlant();
    if(allHarvestablePlant->size() == 0) {
        cout << "Tidak ada tanaman yang siap dipanen." << endl;
        return;
    }

    cout << "\nPilih tanaman siap panen yang kamu miliki" << endl;
    for(int i = 0; i < allHarvestablePlant->size(); i++) {
        while((*allHarvestablePlant)[i].getQuantity() == 0) {
            // pop the element
            allHarvestablePlant->erase(allHarvestablePlant->begin() + i);
        }
        cout << "  " << i+1 << ". " << (*allHarvestablePlant)[i].getValue()->getCode()
        << " (" << (*allHarvestablePlant)[i].getQuantity() << " petak siap panen)"
        << endl;
    }

    int chosenPlantIdx;
    cout << "\nNomor tanaman yang ingin dipanen: ";
    cin >> chosenPlantIdx;
    if(chosenPlantIdx > allHarvestablePlant->size() || chosenPlantIdx < 1) 
        throw out_of_range("Index di luar batas.");

    int amountOfSquareToHarvest;
    cout << "\nBerapa petak yang ingin dipanen: " << endl << endl;

    cin >> amountOfSquareToHarvest;
    if(amountOfSquareToHarvest < 1) 
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh kurang dari 1.");
    if(amountOfSquareToHarvest > (*allHarvestablePlant)[chosenPlantIdx-1].getQuantity()){
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh lebih dari jumlah tanaman yang dimiliki!\nJumlah tanaman yang dimiliki: " + to_string((*allHarvestablePlant)[chosenPlantIdx-1].getQuantity()) + "\n");
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
            throw invalid_argument("Tanaman yang dipilih tidak sesuai.\nSeharusnya: " + chosenPlant->getCode() + "\nDitemukan: " + ladang[l]->getCode());
        }
        chosenPlantLocation.push_back(l);
    }

    // pop the plant and put the result to inventory
    for(const auto &loc : chosenPlantLocation) {
        Plant* p = ladang.pop(loc);
        vector<Product *>& drops = p->harvest();
        for(Product *product : drops) {
            cout << product->getName() << endl;
            petani->putInventory(*product);
        }
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
    CetakPeternakan printer(state);
    printer.printGrid(peternakan);
    printer.printInfo(peternakan);

    vector<Quantifiable<Animal *>>* allHarvestableAnimal = peternak->getAllHarvestableAnimal();
    if(allHarvestableAnimal->size() == 0) {
        cout << "Tidak ada tanaman yang siap dipanen." << endl;
        return;
    }

    cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
    for(int i = 0; i < allHarvestableAnimal->size(); i++) {
        while((*allHarvestableAnimal)[i].getQuantity() == 0) {
            // pop the element
            allHarvestableAnimal->erase(allHarvestableAnimal->begin() + i);
        }
        cout << "  " << i+1 << ". " << (*allHarvestableAnimal)[i].getValue()->getCode()
        << " (" << (*allHarvestableAnimal)[i].getQuantity() << " petak siap panen)"
        << endl;
    }

    int chosenAnimalIdx;
    cout << "\nNomor tanaman yang ingin dipanen: ";
    cin >> chosenAnimalIdx;
    if(chosenAnimalIdx > allHarvestableAnimal->size() || chosenAnimalIdx < 1) 
        throw out_of_range("Index di luar batas.");

    int amountOfSquareToHarvest;
    cout << "\nBerapa petak yang ingin dipanen: ";

    cin >> amountOfSquareToHarvest;
    if(amountOfSquareToHarvest < 1) 
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh kurang dari 1.");
    if(amountOfSquareToHarvest > (*allHarvestableAnimal)[chosenAnimalIdx-1].getQuantity()){
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh lebih dari jumlah tanaman yang dimiliki!\nJumlah tanaman yang dimiliki: " + to_string((*allHarvestableAnimal)[chosenAnimalIdx-1].getQuantity()) + "\n");
    }

    int notFilledAmount = peternakan.getCountNotFilled();
    if(amountOfSquareToHarvest > notFilledAmount) {
        throw out_of_range("Jumlah penyimpanan tidak cukup!\nJumlah penyimpanan yang tidak terisi: " + to_string(notFilledAmount));
    }

    cout << "Pilih petak yang ingin dipanen:" << endl;

    Animal *chosenAnimal = (*allHarvestableAnimal)[chosenAnimalIdx-1].getValue();
    vector<Location> chosenAnimalLocation;
    for(int i = 0; i < amountOfSquareToHarvest; i++){
        cout << "Petak ke-" << i+1 << ": ";
        Location l; cin >> l;
        if(peternakan[l]->getCode() != chosenAnimal->getCode()) {
            throw invalid_argument("Tanaman yang dipilih tidak sesuai.\n Seharusnya: " + chosenAnimal->getCode() + "\nDitemukan: " + peternakan[l]->getCode());
        }
        chosenAnimalLocation.push_back(l);
    }
    
    // pop the Animal and put the result to inventory
    for(const auto &loc : chosenAnimalLocation) {
        Animal* p = peternakan.pop(loc);
        vector<Product *>& drops = p->harvest();
        for(Product *product : drops) {
            peternak->putInventory(*product);
        }
    }

    cout << chosenAnimalLocation.size() << " petak tanaman " << chosenAnimal->getCode() << " pada petak ";
    cout << chosenAnimalLocation[0];
    for(int i = 1; i < chosenAnimalLocation.size(); i++) {
        cout << ", " << chosenAnimalLocation[i];
    }
    cout << " telah dipanen!" << endl; 

    delete allHarvestableAnimal;
}
void Panen::execute(Walikota *walikota) {
    throw CommandNotAllowedException("PANEN");
}
