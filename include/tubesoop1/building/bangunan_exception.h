#ifndef BANGUNAN_EXCEPTION_H
#define BANGUNAN_EXCEPTION_H

using namespace std;
#include <exception>

class RoleWaliKotaException: public exception{
    const char* what() const throw();

};
class SlotNotAvailableException: public exception{
    const char* what() const throw() ;
};

class NotEnoughMaterialException: public exception{
    const char* what() const throw();
};

class NotEnoughMoneyException: public exception{
    const char* what() const throw() ;
};


#endif