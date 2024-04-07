#ifndef STATE_EXCEPTION_H
#define STATE_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class InvalidPlayerTypeException : public exception
{
private:
    const string message;
public:
    InvalidPlayerTypeException(const string &type);
    const char* what() const throw();
};

#endif