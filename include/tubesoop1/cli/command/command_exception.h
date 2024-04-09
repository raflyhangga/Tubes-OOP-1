#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include <exception>
#include <iostream>
using namespace std;

class CommandNotAllowedException: public exception {
    private:
        string command;
    public:
        CommandNotAllowedException(const char* command) {
            this->command = command;
        }
        const char* what() const throw() {
            return ("Command " + command + " is not allowed for this specific role.").c_str();
        }
};

#endif