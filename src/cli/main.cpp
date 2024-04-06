#include <iostream>
#include <string>
#include <map>
#include <functional>

#include <tubesoop1/icosihexastring/icosihexastring.h>
#include <tubesoop1/grid/location.hpp>
#include <tubesoop1/grid/griddrawer.hpp>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/animal/animal.h>
#include <tubesoop1/plant/plant.h>
#include <tubesoop1/grid/grid.h>
#include <tubesoop1/resource/resourcefactory.h>
#include <tubesoop1/player/player.h>
#include <tubesoop1/cli/command/command.hpp>

using namespace std;

int turn = 0;
vector<Player*> players;



int main()
{
    cout << "[Welcome to TUBES-OOP-1]" << endl;

    ResourceFactory factory = ResourceFactory("config");
    cout << factory << endl;

    Resource *r = factory.translate("HORSE");
    cout << r->getCode() << ": " << r->getPrice() << endl;
    
    // Resource* r = factory.translate("SANDALWOOD_WOOD");
    // cout << r->getName() << endl;

    map<string, function<void(Player*)>> commands;

    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        try {
            commands[command](players[turn]);
        } catch(const exception &e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}