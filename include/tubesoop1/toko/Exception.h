#ifndef EXCEPTION_H
#define EXCEPTION_H

using namespace std;
#include <exception>

struct ItemTokoNotFoundException: public exception{
    const char* what() const throw() {
		return "Item pada toko tidak ditemukan";
	}

};
struct ItemTokoNotEqualException: public exception{
    const char* what() const throw() {
		return "Kedua item tidak sama";
	}
};


#endif