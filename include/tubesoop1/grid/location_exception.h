#ifndef LOCATION_EXCEPTION_H
#define LOCATION_EXCEPTION_H

#include <exception>
using namespace std;

class LocationException : public exception {
    public:
        LocationException();
        const char* what() const throw();
};
#endif