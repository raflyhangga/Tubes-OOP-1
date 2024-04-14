#include "tubesoop1/cli/command/makan.h"
#include "tubesoop1/cli/command/cetakpenyimpanan.h"
#include "tubesoop1/grid/location_exception.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/animal/animal_exception.h"

#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include "tubesoop1/cli/command/command_exception.h"
Makan::Makan(State &state) : Command(state) {}

void Makan::execute(Player* player){
    // TO DO validasi penyimpanan apakah ada makanan/kosong

    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();

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
            
            player->eat(*food);
            inventory.pop(loc);
            cout << "Kenyang gan, berat badan naik " << food->getAddedWeight() << " kg jadi " << player->getWeight() <<  endl;
            inputNotCorrect = false;
        }
        catch(logic_error& e){
            cout << "Itu slot kosong gan.\n" << endl;
            cout << "Masukkan slot lagi brok." << endl;
        }
        catch(NotTakableException& e){
            cout << e.what() << endl;
            cout << "Masukkan slot lagi brok." << endl;
        }
        catch(CannotEatException& e){
            cout << "Keras, makanannya ga bisa digigit." << endl;
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