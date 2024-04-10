#include "tubesoop1/cli/command/makan.h"
#include "tubesoop1/cli/command/cetakpenyimpanan.h"
#include "tubesoop1/grid/location_exception.hpp"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"

#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include "tubesoop1/cli/command/command_exception.h"
Makan::Makan(State &state) : Command(state) {}

void Makan::execute(Player* player){
    // TO DO validasi penyimpanan apakah ada makanan/kosong

    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();
    Player* currPlayer = state.getCurrentPlayer();

    if(inventory.getCountFilled() == 0){
       throw(EmptyInventoryException());
    }
    
    vector<ProductFruit*> fruitList = player->takeAllFromInventory<ProductFruit>();
    vector<ProductAnimal*> animalList = player->takeAllFromInventory<ProductAnimal>();

    if(fruitList.size() == 0 && animalList.size() == 0){
        throw(NoFoodException());
    }


    cout << "Pilih makanan dari penyimpanan" << endl;
    CetakPenyimpanan(state).print(player->getInventory());
    Location loc;
    bool inputNotCorrect = true;
    do{
        cout << "Slot: ";
        try{
            cin >> loc;
            
            Product *food = player->takeInventory<Product>(loc);
            
            currPlayer->eat(*food);
            inventory.pop(loc);
            cout << "Kenyang gan, berat badan naik " << food->getAddedWeight() << " kg jadi " << currPlayer->getWeight() <<  endl;
            inputNotCorrect = false;
        }
        catch(LocationException& e){
            cout << e.what() << endl;
            cout << "Masukkan slot lagi brok." << endl;
        }
        catch(NotTakableException& e){
            cout << e.what() << endl;
            cout << "Masukkan slot lagi brok." << endl;
        }
        catch(exception& e){
            cout << e.what() << endl;
            cout << "Masukkan slot lagi brok." << endl;
        }
    } while(inputNotCorrect);
        
        
    
    
   
    

    
    
    // validasi dll bloman

    // to do, check if location is valid (is food, is not empty, etc)



}