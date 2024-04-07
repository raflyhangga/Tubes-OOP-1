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
struct ItemTokoEmptyException: public exception{
    const char* what() const throw() {
		return "Stok Habis";
	}
};
struct UangTidakCukupException: public exception{
    const char* what() const throw() {
		return "Uang yang dimiliki tidak cukup";
	}
};
struct PetaniException: public exception{
    const char* what() const throw() {
		return "Petani tidak bisa membeli barang ini";
	}
};
struct PeternakException: public exception{
    const char* what() const throw() {
		return "Peternak tidak bisa membeli barang ini";
	}
};



#endif