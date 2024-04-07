#ifndef EXCEPTION_H
#define EXCEPTION_H

using namespace std;
#include <exception>

struct ItemShopNotFoundException: public exception{
    const char* what() const throw() {
		return "Item is not available in shop";
	}

};
struct ItemShopNotEqualException: public exception{
    const char* what() const throw() {
		return "Both Item is not equal";
	}
};
struct ItemShopEmptyException: public exception{
    const char* what() const throw() {
		return "Stock is empty";
	}
};
struct UangTidakCukupException: public exception{
    const char* what() const throw() {
		return "Insufficient balance";
	}
};
struct PetaniException: public exception{
    const char* what() const throw() {
		return "Farmer Role can't buy this item";
	}
};
struct PeternakException: public exception{
    const char* what() const throw() {
		return "Rancher Role can't buy this item";
	}
};



#endif