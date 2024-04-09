#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include <exception>
#include <iostream>
#include "tubesoop1/player/player.h"
using namespace std;

class CommandNotAllowedException: public exception {
    private:
        string message;
    public:
        CommandNotAllowedException(string command);
        const char* what() const throw();
};

class CommandNotExistException: public exception {
    private:
        string message;
    public:
        CommandNotExistException(string command);
        const char* what() const throw();
};

class InvalidInputLocationListException: public exception {
    public:
        InvalidInputLocationListException();
        const char* what() const throw();
};

class CannotPanenException: public exception {
    private:
        string message;
    public:
        CannotPanenException(Player &walikota);
        const char* what() const throw();
};

#endif