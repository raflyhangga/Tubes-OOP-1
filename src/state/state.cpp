#include "tubesoop1/state/state.h"

State::State(string statePath, ResourceFactory &factory){
    load(statePath, factory);
}

void State::load(string statePath, ResourceFactory &factory){
    ifstream file(statePath);
    if(!file.is_open()) throw FileNotFoundException(statePath);

    int playerCount;
    file >> playerCount;

    string name, type, weight, money;
    int inventoryCount;
    for(int i = 0; i < playerCount; i++) {
        file >> name >> type >> weight >> money >> inventoryCount;
        Player *currentPlayer;
        if(type == "Petani") currentPlayer = new Petani(name);
        else if(type == "Peternak") currentPlayer = new Peternak(name);
        else if(type == "Walikota") currentPlayer = new Walikota(name);
        else throw InvalidPlayerTypeException(type);

        for(int i = 0; i < inventoryCount; i++) {
            string itemName;
            file >> itemName;
            Resource *r = factory.translate(itemName);
            currentPlayer->putInventory(*r);
        }

        
        if(type == "Petani"){
            int plantCount;
            file >> plantCount;
            for(int i = 0; i < plantCount; i++) {
                Location location;
                string name;
                int age;
                file >> location >> name >> age;
                Plant *plant = (Plant*)factory.translate(name);
                plant->setAge(age);
                ((Petani*)currentPlayer)->putLadangAt(*plant, location);
            }
        }
        else if(type == "Peternak"){
            int animalCount;
            file >> animalCount;
            for(int i = 0; i < animalCount; i++) {
                Location location;
                string name;
                int weight;
                file >> location >> name >> weight;
                Animal *animal = (Animal*)factory.translate(name);
                animal->setWeight(weight);
                ((Peternak*)currentPlayer)->putPeternakanAt(*animal, location);
            }
        }

        this->playerList.push_back(currentPlayer);
    }

    int shopStockCount;
    file >> shopStockCount;
    for(int i = 0; i < shopStockCount; i++) {
        string itemName;
        int itemAmount;
        file >> itemName >> itemAmount;
        Resource *r = factory.translate(itemName);
        Quantifiable<Resource*> qr = Quantifiable<Resource*>(r, itemAmount);
        // Shop.addItem(*r);
    }

    file.close();
}

void State::save(string statePath){
    ofstream file(statePath);
    if(!file.is_open()) throw FileNotFoundException(statePath);

    int playerCount = playerList.size();

    string name, type, weight, money;
    int inventoryCount;
    file << inventoryCount << endl;

    for(int i = 0; i < playerCount; i++) {
        Player *currentPlayer = playerList[i];
        name = currentPlayer->getUsername();
        weight = currentPlayer->getWeight();
        money = currentPlayer->getMoney();
        type = getClassName(*currentPlayer);
        // inventoryCount = currentPlayer->getInventoryCount();
        // vector<Resource*> inventoryList = currentPlayer->getInventoryAsVector();
        inventoryCount = 2;
        vector<Resource*> inventoryList;

        file << name << " " << type << " " << weight << " " << money << " " << endl << inventoryCount << endl;

        for(int i = 0; i < inventoryCount; i++) {
            string itemName = inventoryList[i]->getName();
            file << itemName << endl;
        }

        
        if(type == "Petani"){
            int plantCount; // = ((Petani*)currentPlayer)->getLadangCount();
            file << plantCount << endl;
            for(int i = 0; i < plantCount; i++) { // grid iteration
                // Plant *plant = ((Petani*)currentPlayer)->getLadangAt(i);
                Plant *plant;
                Location location;
                string name = plant->getName();
                int age = plant->getAge();
                // file << location << " " << name << " " << age;
            }
        }
        else if(type == "Peternak"){
            int animalCount; // = ((Peternak*)currentPlayer)->getLadangCount();
            file << animalCount << endl;
            for(int i = 0; i < animalCount; i++) { // grid iteration
                // Plant *plant = ((Peternak*)currentPlayer)->getLadangAt(i);
                Plant *plant;
                Location location;
                string name = plant->getName();
                int age = plant->getAge();
                // file << location << " " << name << " " << age;
            }
        }

    }

    file.close();
}

void State::addPlayer(string type, string name){
    Player *currentPlayer;
    transform(type.begin(), type.end(), type.begin(), ::tolower); // lowercase
    if(type == "petani") currentPlayer = new Petani(name);
    else if(type == "peternak") currentPlayer = new Peternak(name);
    else if(type == "walikota") currentPlayer = new Walikota(name);
    else throw InvalidPlayerTypeException(type);
    playerList.push_back(currentPlayer);
}

const char* State::getClassName(Player &player){
    const type_info& typeInfo = typeid(player);
    const char* typeName = typeInfo.name();
    const char* mangledName = typeInfo.name();
    int prefixLength = 0;
    while (std::isdigit(mangledName[prefixLength])) {
        prefixLength++;
    }
    const char* className = mangledName + prefixLength;
    return className;
}