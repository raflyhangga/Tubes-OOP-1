#include <iostream>
#include <string>

#include <tubesoop1/icosihexastring.h>
#include <tubesoop1/grid/location.hpp>
#include <tubesoop1/grid/griddrawer.hpp>

using namespace std;

void handleCommand(const string &command) {

}

int main()
{
    cout << "[Welcome to TUBES-OOP-1]" << endl;

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

    Location loc;
    cin >> loc;
    cout << loc.getCol() << ' ' << loc.getRow() << endl;
    
    // vector<Plant> plantList = TxtParser::fromtxt<Plant>("config/plant.txt");

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << plantList[i] << endl;
    // }
    // TxtParser::totxt("config/plant.txt", plantList);

    return 0;
}