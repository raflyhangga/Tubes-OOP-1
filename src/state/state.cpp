#include "tubesoop1/state/state.h"

State::State(){}

State::State(string statePath, ResourceFactory &factory) {
    load(statePath, factory);
}

State::State(ResourceFactory &factory){
    loadNew(factory);
}

void State::loadNew(ResourceFactory &factory){
    turn = 0;

    string name1 = "Petani1";
    Petani *petani1 = new Petani(name1);

    string name2 = "Peternak1";
    Peternak *peternak1 = new Peternak(name2);

    string name3 = "Walikota";
    Walikota *walikota = new Walikota(name3);

    playerList.push_back(petani1);
    playerList.push_back(peternak1);
    playerList.push_back(walikota);

    sort(playerList.begin(), playerList.end(), [](Player* a, Player* b) {
        return a->getUsername() < b->getUsername();
    });
}

void State::load(string statePath, ResourceFactory &factory){
    turn = 0;

    ifstream file(statePath);
    if(!file.is_open()) throw FileNotFoundException(statePath);

    int playerCount;
    file >> playerCount;

    string name, type;
    int weight, money;
    int inventoryCount;
    for(int i = 0; i < playerCount; i++) {
        file >> name >> type >> weight >> money >> inventoryCount;
        Player *currentPlayer;
        if(type == "Petani") currentPlayer = new Petani(name);
        else if(type == "Peternak") currentPlayer = new Peternak(name);
        else if(type == "Walikota") currentPlayer = new Walikota(name);
        else throw InvalidPlayerTypeException(type);
        currentPlayer->setWeight(weight);
        currentPlayer->setMoney(money);

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
        shop.addItem(qr);
    }

    file.close();
}

void State::save(string statePath){
    ofstream file(statePath);
    if(!file.is_open()) throw FileNotFoundException(statePath);

    int playerCount = playerList.size();

    string name, type;
    int weight, money;
    int inventoryCount;
    file << playerCount << endl;

    for(int i = 0; i < playerCount; i++) {
        Player *currentPlayer = playerList[i];
        name = currentPlayer->getUsername();
        weight = currentPlayer->getWeight();
        money = currentPlayer->getMoney();
        type = getClassName(*currentPlayer);
        Grid<Resource*>& inventory = currentPlayer->getInventory();
        inventoryCount = inventory.getCountFilled();

        file << name << " " << type << " " << weight << " " << money << " " << endl << inventoryCount << endl;
        
        for(Location location : inventory){
            Resource *r = inventory.getElement(location);
            string itemName = r->getName();
            file << itemName << endl;
        }
        
        if(type == "Petani"){
            Grid<Plant*>& ladang = ((Petani*)currentPlayer)->getLadang();
            int plantCount = ladang.getCountFilled();
            file << plantCount << endl;

            for(Location location : ladang){
                Plant *plant = ladang.getElement(location);
                string name = plant->getName();
                int age = plant->getAge();
                file << location << " " << name << " " << age << endl;
            }
        }
        else if(type == "Peternak"){
            Grid<Animal*>& peternakan = ((Peternak*)currentPlayer)->getPeternakan();
            int animalCount = peternakan.getCountFilled();
            file << animalCount << endl;

            for(Location location : peternakan){
                Animal *animal = peternakan.getElement(location);
                string name = animal->getName();
                int weight = animal->getWeight();
                file << location << " " << name << " " << weight << endl;
            }
        }

    }

    int shopStockCount = shop.getstock().size();
    file << shopStockCount << endl;
    vector<Quantifiable<Resource*>> stock = shop.getstock();
    for(int i = 0; i < shopStockCount; i++) {
        string itemName = stock[i].getValue()->getName();
        int itemAmount = stock[i].getQuantity();
        file << itemName << " " << itemAmount << endl;
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

State::~State(){
    for(Player *player : playerList){
        delete player;
    }
}

Player* State::getCurrentPlayer(){
    return playerList[turn % playerList.size()];
}

void State::nextTurn(){
    turn++;
}