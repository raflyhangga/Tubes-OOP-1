#include "tubesoop1/cli/command/kasihmakan.h"
#include "tubesoop1/cli/command/command_exception.h"
#include "tubesoop1/cli/command/cetakpenyimpanan.h"
#include "tubesoop1/cli/command/cetakpeternakan.h"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include "tubesoop1/grid/location_exception.hpp"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"

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

    Player *player = state.getCurrentPlayer();

    if(peternakan.getCountFilled() == 0){
        cout << ("Tidak ada hewan di peternakan!\n");
        return;
    }
    
    CetakPeternakan(state).printGrid(peternakan);

    cout << "Petak kandang : ";
    Location loc;
    
    try{
        cin >> loc;
        Animal *animal = peternakan.getElement(loc);
        

        cout << "Kamu memilih " << animal->getName() << " untuk diberi makan." << endl;


        cout << "Pilih pangan yang akan diberikan: " << endl;

        CetakPenyimpanan(state).print(inventory);

        cout << "Slot: ";
        Location loc2;
        cin >> loc2;

        Product *p = player->takeInventory<Product>(loc2);
        

        animal->eat(*p);
        cout << animal->getName() << " sudah diberi makan dan beratnya menjadi " << animal->getWeight() << endl;
        
        inventory.pop(loc2);
        
    
    }
    catch(LocationException &e){
        cout << e.what() << endl;
    }
    catch(NotTakableException &e){
        cout << e.what() << endl;
    }

    
    

}
