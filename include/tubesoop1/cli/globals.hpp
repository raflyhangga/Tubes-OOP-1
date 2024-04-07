#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tubesoop1/player/player.h>
#include <tubesoop1/cli/command/command.hpp>

using namespace std;

class Globals {
    public:
        static int turn;
        static vector<Player*> players;
        static map<string, Command*> commands;
};

#endif