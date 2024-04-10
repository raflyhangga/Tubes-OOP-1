#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <functional>

#include <tubesoop1/grid/location.h>
#include <tubesoop1/grid/griddrawer.hpp>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/animal/animal.h>
#include <tubesoop1/animal/animal_exception.h>
#include <tubesoop1/plant/plant.h>
#include <tubesoop1/grid/grid.h>
#include <tubesoop1/resource/resourcefactory.h>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/player_partial.hpp>

#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>

#include <tubesoop1/state/state.h>

#include <tubesoop1/cli/game.h>
#include <tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h>
#include <tubesoop1/resourcevisitorpattern/taker.hpp>

using namespace std;

int main()
{
    // ResourceFactory factory("config");
    // State state("config/state.txt", factory);
    // state.nextTurn();
    // Player* p = state.getCurrentPlayer();
    // Grid<Resource*>& inventory = p->getInventory();
    // GridDrawerCLI<Resource*> drawer(inventory);
    // drawer.draw();
    // vector<Animal*> v;    

    // // Taker<Animal> animalTaker;
    // // AnimalTaker animalTaker2;
    // // for(const auto &it : inventory) {
    // //     Resource* r = inventory[it];
    // //     try{
    // //         v.push_back(animalTaker.take(r)->get());
    // //         // v.push_back(Taker<Animal>().take(r)->get()); // juga one liner
    // //     } catch(exception &e) {
    // //         cout << e.what() << endl;
    // //     } catch(NotTakableException &e) {
    // //         cout << e.what() << endl;
    // //     }
    // // }



    // Taker<Animal> animalTaker;
    // Location location; cin >> location;
    // Resource* r = inventory[location];
    // cout << animalTaker.take(r)->get()->getName() << endl;

    // // One liner version
    // // Location location; cin >> location;
    // // cout << Taker<Animal>().take(inventory[location])->get()->getName() << endl;

    // // intinya animalTaker.take(r)->get() sebenarnya dynamic_cast tapi 
    // // throw exception kalau gagal instead of jadi null.

    // // cara lain
    // Player* player = state.getCurrentPlayer();
    // Location location2; cin >> location2;
    // Animal* a = player->takeInventory<Animal>(location2);
    // cout << a->getName() << endl;


    // for(auto it : v) {
    //     cout << it->getName() << endl;
    // }

    // vector<Animal*> list = player->takeAllFromInventory<Animal>();
    // for(auto it : list) {
    //     cout << it->getName() << endl;
    // }


    // return 0;

    CLIGame game;
    try {
        game.init();
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
        cout << "Gagal memulai permainan\n";
        return 1;
    }
    game.run();

    // return 0;

    // Resource *r = factory.translate("HORSE");
    // cout << r->getCode() << ": " << r->getPrice() << endl;
    
    // Resource* r = factory.translate("SANDALWOOD_WOOD");
    // cout << r->getName() << endl;


    // Location loc;
    // cin >> loc;
    // cout << loc << endl;


    // Main program
    // cout << "[Welcome to TUBES-OOP-1]" << endl;
    // // ResourceFactory factory("config");
    // Animal *horse = (Animal*)factory.translate("HORSE");
    // Animal *rabbit = (Animal*)factory.translate("RABBIT");
    // Product *apple = (Product*)factory.translate("APPLE");
    // Product *cowMeat = (Product*)factory.translate("COW_MEAT");

    // cout << horse->getName() << rabbit->getName() << apple->getName() << cowMeat->getName() << endl;
    
    // try{
    //     horse->eat(*apple);
    //     rabbit->eat(*apple);
    //     horse->eat(*cowMeat);
    //     rabbit->eat(*cowMeat);
    // } catch (CannotEatException &e) {
    //     cout << e.what() << endl;
    // }

    // return 0;
}