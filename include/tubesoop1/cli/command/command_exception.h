#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include <exception>
#include <iostream>
#include "tubesoop1/player/walikota.h"
using namespace std;

class CommandNotAllowedException: public exception {
    private:
        string message;
    public:
        CommandNotAllowedException(string command);
        const char* what() const throw();
};

class InvalidInputLocationListException: public exception {
    public:
        InvalidInputLocationListException();
        const char* what() const throw();
};

class CannotPanenException: public exception {
    private:
        Walikota& walikota;
    public:
        CannotPanenException(Walikota &walikota);
        const char* what() const throw();
};

#endif