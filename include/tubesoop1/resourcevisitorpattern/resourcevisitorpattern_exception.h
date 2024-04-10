#ifndef RESOURCE_VISITORPATTERN_EXCEPTION_H
#define RESOURCE_VISITORPATTERN_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>
#include "tubesoop1/resource/resource.h"
using namespace std;

class NotTakableException : exception{
    private:
        const string message;
    public:
        NotTakableException(const Resource& r);
        const char* what() const throw();
};

#endif