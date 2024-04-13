#ifndef BANGUNAN_EXCEPTION_H
#define BANGUNAN_EXCEPTION_H



using namespace std;
#include <exception>
#include <map>
#include <string>

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

class MissingResourcesException: public exception{
    private:
        map<string, int> missingResources;
    public:
        MissingResourcesException(map<string, int> missingResources);
        map<string, int> &getMissingResources();
        const char* what() const throw();
};


#endif