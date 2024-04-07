#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <functional>

#include <tubesoop1/icosihexastring/icosihexastring.h>
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

using namespace std;



// global variable
int turn = 0;
vector<Player*> players;
map<string, Command*> commands;

void initializeCommand() {
    commands["NEXT"] = new Next();
    commands["CETAK_PENYIMPANAN"] = new CetakPenyimpanan();
}

void initializeGame() {
    string name1 = "Petani1";
    Petani *petani1 = new Petani(name1);

    string name2 = "Peternak1";
    Peternak *peternak1 = new Peternak(name2);

    string name3 = "Walikota";
    Walikota *walikota = new Walikota(name3);

    players.push_back(walikota);
    players.push_back(petani1);
    players.push_back(peternak1);

    sort(players.begin(), players.end(), [](Player* a, Player* b) {
        return a->getUsername() < b->getUsername();
    });

    cout << "Giliran " << players[turn]->getUsername() << " yang bermain." << endl;
}

int main()
{

    ResourceFactory factory = ResourceFactory("config");
    cout << factory << endl;

    // Resource *r = factory.translate("HORSE");
    // cout << r->getCode() << ": " << r->getPrice() << endl;
    
    // Resource* r = factory.translate("SANDALWOOD_WOOD");
    // cout << r->getName() << endl;


    Location loc;
    cin >> loc;
    cout << loc << endl;


    // Main program
    cout << "[Welcome to TUBES-OOP-1]" << endl;
    Animal *horse = (Animal*)factory.translate("HORSE");
    Animal *rabbit = (Animal*)factory.translate("RABBIT");
    Product *apple = (Product*)factory.translate("APPLE");
    Product *cowMeat = (Product*)factory.translate("COW_MEAT");

    cout << horse->getName() << rabbit->getName() << apple->getName() << cowMeat->getName() << endl;
    
    try{
        horse->eat(*apple);
        rabbit->eat(*apple);
        horse->eat(*cowMeat);
        rabbit->eat(*cowMeat);
    } catch (CannotEatException &e) {
        cout << e.what() << endl;
    }

    return 0;

    initializeGame();
    initializeCommand();

    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        try {
            commands[command]->execute(players[turn]);
        } catch(const bad_function_call &e) {
            cout << "Tidak ada command \"" << command << "\"\n";
        } catch (exception &e) {
            cout << e.what() << endl;
        }
    }



    return 0;
}