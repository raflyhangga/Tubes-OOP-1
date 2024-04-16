#include <tubesoop1/cli/command/panen.h>
#include <tubesoop1/cli/command/cetakpeternakan.h>
#include <tubesoop1/cli/command/cetakladang.h>
#include <tubesoop1/cli/command/command_exception.h>
#include <tubesoop1/quantifiable/quantifiable.h>
#include <iostream>
#include <unordered_set>
using namespace std;

Panen::Panen(State &state) : Command(state) {}

void Panen::execute(Petani *petani) {
    Grid<Plant*> &ladang = petani->getLadang();
    CetakLadang printer(state);
    
    printer.printGrid(ladang);
    printer.printInfo(ladang);
 
    vector<Quantifiable<Plant *>>* allHarvestablePlant = petani->getAllHarvestablePlant();
    if(allHarvestablePlant->size() == 0) {
        throw(NoHarvestablePlantException());
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
    string checker;
    int chosenPlantIdx;
    cout << "\nNomor tanaman yang ingin dipanen: ";
    cin >> checker;
    chosenPlantIdx = Command::stringToInt(checker);
    chosenPlantIdx--;
    if(chosenPlantIdx > allHarvestablePlant->size()-1 || chosenPlantIdx < 0) 
        throw out_of_range("Index di luar batas.");

    int amountOfSquareToHarvest;
    cout << "\nBerapa petak yang ingin dipanen: " << endl << endl;

    cin >> checker;
    amountOfSquareToHarvest = Command::stringToInt(checker);
    if(amountOfSquareToHarvest < 1) 
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh kurang dari 1.");
    if(amountOfSquareToHarvest > (*allHarvestablePlant)[chosenPlantIdx].getQuantity()){
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh lebih dari jumlah tanaman yang dimiliki!\nJumlah tanaman yang dimiliki: " + to_string((*allHarvestablePlant)[chosenPlantIdx].getQuantity()) + "\n");
    }

    int notFilledAmount = ladang.getCountNotFilled();
    int panenAmount = amountOfSquareToHarvest * (*allHarvestablePlant)[chosenPlantIdx].getValue()->harvest().size();
    if(panenAmount > notFilledAmount) {
        throw out_of_range("Jumlah penyimpanan tidak cukup!\nPetak kosong di penyimpanan: " + to_string(notFilledAmount) + "\nHasil panen (Jumlah petak x banyak hasil panen): " + to_string(panenAmount) + "\n");
    }

    cout << "Pilih petak yang ingin dipanen:" << endl;

    set<Location> chosenPlantLocationSet;

    Plant *chosenPlant = (*allHarvestablePlant)[chosenPlantIdx].getValue();
    vector<Location> chosenPlantLocation;
    for(int i = 0; i < amountOfSquareToHarvest; i++){
        cout << "Petak ke-" << i+1 << ": ";
        Location l; cin >> l;
        
        if(ladang[l]->getCode() != chosenPlant->getCode()) {
            throw invalid_argument("Tanaman yang dipilih tidak sesuai.\nSeharusnya: " + chosenPlant->getCode() + "\nDitemukan: " + ladang[l]->getCode());
        }
        
        if(chosenPlantLocationSet.find(l) != chosenPlantLocationSet.end()) {
            throw invalid_argument("Duplicate location!");
        }
        chosenPlantLocationSet.insert(l);

        chosenPlantLocation.push_back(l);
    }

    // pop the plant and put the result to inventory
    for(const auto &loc : chosenPlantLocation) {
        Plant* p = ladang.pop(loc);
        vector<Product *>& drops = p->harvest();
        for(Product *product : drops) {
            petani->putInventory(*product);
        }
        // delete p;
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
        throw(NoHarvestableAnimalException());
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

    string checker;
    cout << "\nNomor tanaman yang ingin dipanen: ";
    cin >> checker;
    int chosenAnimalIdx = Command::stringToInt(checker);
    chosenAnimalIdx--;
    if(chosenAnimalIdx >= allHarvestableAnimal->size() || chosenAnimalIdx < 0) 
        throw out_of_range("Index di luar batas.");

    int amountOfSquareToHarvest;
    cout << "\nBerapa petak yang ingin dipanen: ";

    cin >> checker;
    amountOfSquareToHarvest = Command::stringToInt(checker);
    if(amountOfSquareToHarvest < 1) 
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh kurang dari 1.");
    if(amountOfSquareToHarvest > (*allHarvestableAnimal)[chosenAnimalIdx].getQuantity()){
        throw out_of_range("Jumlah petak yang ingin dipanen tidak boleh lebih dari jumlah tanaman yang dimiliki!\nJumlah tanaman yang dimiliki: " + to_string((*allHarvestableAnimal)[chosenAnimalIdx].getQuantity()) + "\n");
    }

    int notFilledAmount = peternakan.getCountNotFilled();
    int panenAmount = amountOfSquareToHarvest * (*allHarvestableAnimal)[chosenAnimalIdx].getValue()->harvest().size();
    if(panenAmount > notFilledAmount) {
        throw out_of_range("Jumlah penyimpanan tidak cukup!\nPetak kosong di penyimpanan: " + to_string(notFilledAmount) + "\nHasil panen (Jumlah petak x banyak hasil panen): " + to_string(panenAmount) + "\n");
    }

    cout << "Pilih petak yang ingin dipanen:" << endl;

    set<Location> chosenAnimalLocationSet;

    Animal *chosenAnimal = (*allHarvestableAnimal)[chosenAnimalIdx].getValue();
    vector<Location> chosenAnimalLocation;
    for(int i = 0; i < amountOfSquareToHarvest; i++){
        cout << "Petak ke-" << i+1 << ": ";
        Location l; cin >> l;
        
        if(peternakan[l]->getCode() != chosenAnimal->getCode()) {
            throw invalid_argument("Tanaman yang dipilih tidak sesuai.\n Seharusnya: " + chosenAnimal->getCode() + "\nDitemukan: " + peternakan[l]->getCode());
        }

        // check if the same coordinate already inputted
        if(chosenAnimalLocationSet.find(l) != chosenAnimalLocationSet.end()) {
            throw invalid_argument("Duplicate location!");
        }
        chosenAnimalLocationSet.insert(l);
        chosenAnimalLocation.push_back(l);
    }
    
    // pop the Animal and put the result to inventory
    for(const auto &loc : chosenAnimalLocation) {
        Animal* p = peternakan.pop(loc);
        vector<Product *>& drops = p->harvest();
        for(Product *product : drops) {
            peternak->putInventory(*product);
        }
        // delete p;
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

