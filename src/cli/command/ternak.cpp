#include "tubesoop1/cli/command/ternak.h"


Ternak::Ternak(State &state) : Command(state) {

}   

void Ternak::execute(Peternak *peternak) {
    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();

    Grid<Animal*> &peternakan = peternak->getPeternakan();

    if(peternak->countAnimalInventory()==0){
        cout << ("Tidak ada hewan di inventory!\n");
        return;
    }
    
    if(peternakan.isFull()){
        cout << ("Peternakan Penuh!\n");
        return;
    }
 
    cout << "Pilih hewan dari penyimpanan" << endl;
    CetakPenyimpanan(state).print(inventory);
    // CetakPenyimpanan::print(inventory);
    cout << "\n";
    cout << "Slot: ";
    Location loc;
    cin >> loc;
    Animal *animal = dynamic_cast<Animal*>(inventory.getElement(loc));
    while(animal ==nullptr){
        cout << "Slot tidak berisi hewan, silahkan pilih slot lain" << endl;
        cout << "Slot: ";
        cin >> loc;
        animal = dynamic_cast<Animal*>(inventory.getElement(loc));
    }
    
    inventory.pop(loc);

    // TO DO, CHECK IF LOCATION IS VALID (is animal, is not empty, etc)

    cout << "Pilih petak tanah yang akan ditinggali" << endl;
    CetakPeternakan(state).printGrid(peternakan);

    cout << "Petak tanah: ";
    Location loc2;
    cin >> loc2;
    peternakan.setElement(loc2, animal);
    cout << "Success" << endl;
    
}

void Ternak::execute(Petani *petani) {
    throw CommandNotAllowedException("TERNAK");
}

void Ternak::execute(Walikota *walikota) {
    throw CommandNotAllowedException("TERNAK");
}