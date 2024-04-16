#include "tubesoop1/cli/command/ternak.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include "tubesoop1/cli/command/command_exception.h"
Ternak::Ternak(State &state) : Command(state) {

}   

void Ternak::execute(Peternak *peternak) {
    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();

    Grid<Animal*> &peternakan = peternak->getPeternakan();

    Player* player = state.getCurrentPlayer();
    
    vector<Animal*> list = player->takeAllFromInventory<Animal>();
    
    
    if(list.size()==0){
        throw(NoAnimalInInventoryException());
    }
    
    if(peternakan.isFull()){
        throw(PeternakanPenuhException());
    }
 
    bool inputNotValid = true;
    do{
        try{
            cout << "Pilih hewan dari penyimpanan" << endl;
            CetakPenyimpanan(state).print(inventory);
        
            Location loc;
            cout << "Slot: ";
            cin >> loc;
            Animal *anim = player->takeInventory<Animal>(loc);

            cout << "Pilih petak tanah yang akan ditinggali" << endl;
            CetakPeternakan(state).printGrid(peternakan);
            cout << "Petak tanah: ";
            Location loc2;
            cin >> loc2;
            peternakan.setElement(loc2, anim);
            cout << "Kamu telah memasukkan " << anim->getName() << " ke kandang" << endl;
            inventory.pop(loc);

            inputNotValid = false;
        }
        catch(const NotTakableException &e){
            // cout << e.what() << endl;
            cout << "\nHEY HEY HEY APA ITU YG MAU ANDA MASUKKAN KE KANDANG!!" << endl;
            cout << "Masukkan slot lagi brok." << endl << endl;

        }

        catch(const exception& e){
            cout << e.what() << endl;
            cout << "Masukkan slot lagi brok." << endl << endl;
        }

    }
    while(inputNotValid);
    
}

void Ternak::execute(Petani *petani) {
    throw CommandNotAllowedException("TERNAK");
}

void Ternak::execute(Walikota *walikota) {
    throw CommandNotAllowedException("TERNAK");
}