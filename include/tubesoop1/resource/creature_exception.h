#ifndef CREATURE_EXCEPTION_H
#define CREATURE_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>
#include "tubesoop1/resource/creature.h"
using namespace std;

class NotHarvestableException : exception{
    private:
        const string message;
    public:
        NotHarvestableException(const Creature& creature);
        const char* what() const throw();
};

#endif