#include "tubesoop1/cli/command/kasihmakan.h"
#include "tubesoop1/cli/command/command_exception.h"
#include "tubesoop1/cli/command/cetakpenyimpanan.h"
#include "tubesoop1/cli/command/cetakpeternakan.h"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include "tubesoop1/grid/location_exception.h"
#include "tubesoop1/animal/animal_exception.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/cli/command/command_exception.h"

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
        throw AnimalNotFoundException(); 
    }
    
    CetakPeternakan(state).printGrid(peternakan);

    cout << "Petak kandang : ";
    Location loc;
    
    try{
        cin >> loc;
        Animal *animal = peternakan.getElement(loc);

        // Check if there's no food that can be given to the animal
        vector<Product*> productList = peternak->takeAllFromInventory<Product>();
        // If there exist a product that can be given to the animal, then the player can give food to the animal
        bool canEat = false;
        // cout << "\n berat animal: "<< animal->getWeight() << endl;
        for(Product* product : productList){
            try{
                animal->eat(*product);
                canEat = true;
                animal->setWeight(animal->getWeight() - product->getAddedWeight());
                break;
            } catch (CannotEatException &e) {}
        }
        if(!canEat){
            throw NoFoodForAnimalException("Makanan yang bisa diberikan kepada "+animal->getName()+" tidak tersedia!");
        }
        

        cout << "Kamu memilih " << animal->getName() << " untuk diberi makan." << endl;


        cout << "Pilih pangan yang akan diberikan: " << endl;

        CetakPenyimpanan(state).print(inventory);

        cout << "Slot: ";
        Location loc2;
        cin >> loc2;

        Product *p = player->takeInventory<Product>(loc2);
        

        animal->eat(*p);
   

        cout << animal->getName() << " sudah diberi makan dan beratnya menjadi meningkat dari " << animal->getWeight() - p->getAddedWeight() <<" menjadi " <<  animal->getWeight() << endl;
        
        inventory.pop(loc2);
        
    
    } catch (LocationException &e){
        cout << e.what() << endl;
    } catch (NotTakableException &e){
        cout << e.what() << endl;
    } catch (CannotEatException &e) {
        cout << e.what() << endl;
    } 

    
    

}
