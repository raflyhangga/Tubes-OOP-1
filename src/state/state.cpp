#include "tubesoop1/state/state.h"

State::State(){}

State::State(string statePath, ResourceFactory &factory) {
    load(statePath, factory);
}

State::State(ResourceFactory &factory){
    loadNew(factory);
}

void State::loadNew(ResourceFactory &factory){
    this->factory = &factory;
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

    for(Resource* rsc:factory.getCreatureResources()){
        Quantifiable<Resource*> qr = Quantifiable<Resource*>(rsc, -1);
        shop.addItem(qr);
    }

    for(Resource* rsc:factory.getNonCreatureReesources()){
        Quantifiable<Resource*> qr = Quantifiable<Resource*>(rsc, 0);
        shop.addItem(qr);
    }

    sort(playerList.begin(), playerList.end(), [](Player* a, Player* b) {
        return a->getUsername() < b->getUsername();
    });
}

void State::load(string statePath, ResourceFactory &factory){
    this->factory = &factory;
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

    // For Limited Stock
    for(Resource* rsc:factory.getCreatureResources()){
        Quantifiable<Resource*> qr = Quantifiable<Resource*>(rsc, -1);
        shop.addItem(qr);
    }

    for(Resource* rsc:factory.getNonCreatureReesources()){
        Quantifiable<Resource*> qr = Quantifiable<Resource*>(rsc, 0);
        shop.addItem(qr);
    }

    for(int i = 0; i < shopStockCount; i++) {
        string itemName;
        int itemAmount;
        file >> itemName >> itemAmount;
        Resource *r = factory.translate(itemName);
        Quantifiable<Resource*> qr = Quantifiable<Resource*>(r, itemAmount);
        shop.addItem(qr);
    }


    sort(playerList.begin(), playerList.end(), [](Player* a, Player* b) {
        return a->getUsername() < b->getUsername();
    });

    file.close();
}

void State::save(string statePath){
    ofstream file(statePath);
    if(!file.is_open()) throw FolderNotFoundException(statePath);

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
        ClassVisitor classTranslator; classTranslator.execute(currentPlayer); type = classTranslator.get();
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
    file << shop.countFiniteStock() << endl;
    vector<Quantifiable<Resource*>> stock = shop.getstock();
    for(int i = 0; i < shop.getstock().size(); i++) {
        if(stock[i].isInfinite()) continue; // Skip infinite stock
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
    
    playerList.insert(playerList.begin() + turn + 1, currentPlayer);
    currentPlayer->setWeight(0);
    
    sort(playerList.begin(), playerList.end(), [](Player* a, Player* b) {
        return a->getUsername() < b->getUsername();
    });
    
}
bool State::isAddedTypeValid(string &type){
    transform(type.begin(), type.end(), type.begin(), ::tolower); // lowercase
    return type == "petani" || type == "peternak";
}
bool State::isPlayerExist(string nameToCheck){
    transform(nameToCheck.begin(), nameToCheck.end(), nameToCheck.begin(), ::tolower); // lowercase

    for(Player *player : playerList){
        string username = player->getUsername();
        transform(nameToCheck.begin(), nameToCheck.end(), nameToCheck.begin(), ::tolower); // lowercase
        transform(username.begin(), username.end(), username.begin(), ::tolower); // lowercase
        if(username == nameToCheck) return true;
    }
    return false;
}

State::~State(){
    for(Player *player : playerList){
        delete player;
    }
}

Player* State::getCurrentPlayer(){
    return playerList[turn % playerList.size()];
}
int State::getTotalPlayer(){
    return playerList.size();
}

void State::nextTurn(){
    turn = (turn + 1) % playerList.size();
}

Player* State::getPlayer(int index){
    return playerList[index];
}

vector<Player*>& State::getPlayerList(){
    return playerList;
}

Resource* State::translate(string itemName){
    Resource *r = factory->translate(itemName);
    return r;
}

int State::getTurn(){
    return turn;
}


void State::addShopItem(Quantifiable<Resource*> item){
    shop.addItem(item);
}

void State::cancelBuyShopItem(int idxItem, int quantity){
    shop.cancelBuy(idxItem,quantity);
}

map<string, Building*>& State::getRecipeMap(){
    return factory->getRecipeMap();
}

Shop& State::getShop() {
    return shop; 
}
bool State::tryGetWinningPlayer(Player* player){
    for(Player* p : playerList){
        if(p->isWin()){
            player = p;
            return true;
        }
    }
    return false;
}





void State::ClassVisitor::execute(Player* player) {
    player->executed(*this);
}
string State::ClassVisitor::get(){
    return className;
}
void State::ClassVisitor::execute(Petani* player) {
    className = "Petani";
}
void State::ClassVisitor::execute(Peternak* player) {
    className = "Peternak";
}
void State::ClassVisitor::execute(Walikota* player) {
    className = "Walikota";
}