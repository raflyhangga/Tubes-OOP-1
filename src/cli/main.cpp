#include <iostream>
#include <string>
#include <algorithm>
#include <map>
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
#include <tubesoop1/cli/command/command.hpp>

#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>

#include <tubesoop1/cli/command/next.hpp>
#include <tubesoop1/cli/command/cetakpenyimpanan.hpp>
#include <tubesoop1/state/state.h>

#include <tubesoop1/cli/globals.hpp>
#include <tubesoop1/cli/game.hpp>

using namespace std;

int main()
{

    ResourceFactory factory = ResourceFactory("config");
    cout << factory << endl;

    // try{
    //     State state = State("config/state.txt", factory);
    //     state.save("config/state2.txt");
    // } catch (exception &e) {
    //     cout << e.what() << endl;
    // }

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

    Grid<int> g;
    g.setElement(Location(0, 0), 1); // A01
    g.setElement(Location(1, 4), 1); // E02
    g.setElement(Location(0, 2), 1); // C01
    for(const auto &loc: g) {
        cout << loc << endl;
    }

    CLIGame game;
    try {
        game.init();
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
        cout << "Gagal memulai permainan\n";
        return 1;
    }
    game.run();

    return 0;
}