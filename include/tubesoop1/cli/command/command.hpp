#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
using namespace std;

class Command {
    public:
        virtual void execute() = 0;
};



#endif