#ifndef EXCEPTION_H
#define EXCEPTION_H

using namespace std;
#include <exception>

class ItemShopNotFoundException: public exception{
    const char* what() const throw() {
		return "Item is not available in shop";
	}

};
class ItemShopNotEqualException: public exception{
    const char* what() const throw() {
		return "Both Item is not equal";
	}
};
class ItemShopEmptyException: public exception{
    const char* what() const throw() {
		return "Stock is empty";
	}
};
class UangTidakCukupException: public exception{
    const char* what() const throw() {
		return "Insufficient balance";
	}
};
class PetaniException: public exception{
    const char* what() const throw() {
		return "Farmer Role can't buy this item";
	}
};
class PeternakException: public exception{
    const char* what() const throw() {
		return "Rancher Role can't buy this item";
	}
};



#endif