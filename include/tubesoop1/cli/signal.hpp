#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <iostream>
#include <string>

using namespace std;

class GameOverSignal {
    private:
        string winnersName;
    public:
        GameOverSignal(string name);

        void announce();

};
#endif