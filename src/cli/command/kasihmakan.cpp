#include "tubesoop1/cli/command/kasihmakan.h"
#include "tubesoop1/cli/command/command_exception.h"
#include "tubesoop1/cli/command/cetakpenyimpanan.h"
#include "tubesoop1/cli/command/cetakpeternakan.h"
KasihMakan::KasihMakan(State& state): Command(state) {}


void KasihMakan::execute(Petani* petani) {
    throw CommandNotAllowedException("KASIH_MAKAN");
}

void KasihMakan::execute(Walikota* walkot){
    throw CommandNotAllowedException("KASIH_MAKAN");
}

void KasihMakan::execute(Peternak* peternak){
    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();

    Grid<Animal*> &peternakan = peternak->getPeternakan();

    if(peternakan.getCountFilled() == 0){
        cout << ("Tidak ada hewan di peternakan!\n");
        return;
    }
    
    CetakPeternakan(state).printGrid(peternakan);

    cout << "Petak kandang : ";
    Location loc;
    cin >> loc;

    Animal *animal = peternakan.getElement(loc);
   
    cout << "Kamu memilih " << animal->getName() << " untuk diberi makan." << endl;

    cout << "Pilih pangan yang akan diberikan: " << endl;

    CetakPenyimpanan(state).print(inventory);

    cout << "Slot: ";
    Location loc2;
    cin >> loc2;
    Resource *prod = inventory.getElement(loc2);
    inventory.pop(loc2);
    animal->eat(*prod);

    
}
