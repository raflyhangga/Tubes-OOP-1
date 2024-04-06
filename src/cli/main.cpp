#include <iostream>
#include <string>

#include <tubesoop1/icosihexastring/icosihexastring.h>
#include <tubesoop1/grid/location.hpp>
#include <tubesoop1/grid/griddrawer.hpp>
#include <tubesoop1/resource/resource.h>
#include <tubesoop1/animal/animal.h>
#include <tubesoop1/plant/plant.h>
#include <tubesoop1/grid/grid.h>
#include <tubesoop1/resource/resourcefactory.h>

using namespace std;

void handleCommand(const string &command) {

}

int main()
{
    cout << "[Welcome to TUBES-OOP-1]" << endl;

    ResourceFactory factory = ResourceFactory("config");
    cout << factory << endl;

    Resource *r = factory.translate("HORSE");
    cout << r->getCode() << ": " << r->getPrice() << endl;
    
    // Resource* r = factory.translate("SANDALWOOD_WOOD");
    // cout << r->getName() << endl;

    // string command;
    // while (true) {
    //     cout << "> ";
    //     cin >> command;
    //     try {
    //         handleCommand(command);
    //     } catch(const exception &e) {
    //         cout << e.what() << endl;
    //     }
    // }

    // vector<Plant> plantList = TxtParser::fromtxt<Plant>("config/plant.txt");

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << plantList[i] << endl;
    // }
    // TxtParser::totxt("config/plant.txt", plantList);

    return 0;
}