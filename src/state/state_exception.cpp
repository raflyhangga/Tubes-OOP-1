#include "tubesoop1/state/state_exception.h"

InvalidPlayerTypeException::InvalidPlayerTypeException(const string &type) :
    message(type + " is not a valid Player type") 
{}

const char* InvalidPlayerTypeException::what() const throw(){
    return message.c_str();
}
