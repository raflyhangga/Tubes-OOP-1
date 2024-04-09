#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include <exception>
#include <iostream>
using namespace std;

class CommandNotAllowedException: public exception {
    private:
        string message;
    public:
        CommandNotAllowedException(string command);
        const char* what() const throw();
};

#endif