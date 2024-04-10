#ifndef BELI_EXCEPTION_H
#define BELI_EXCEPTION_H

using namespace std;
#include <exception>

class BeliOutOfRange: public exception{
    const char* what() const throw() {
		return "Barang tidak ditemukan";
	}
};

class BarangTidakCukup: public exception{
    const char* what() const throw() {
		return "Kuantitas tidak mencukupi";
	}
};

class UangTidakCukup: public exception{
    const char* what() const throw() {
		return "Uang tidak mencukupi";
	}
};

class PenyimpananTidakCukup: public exception{
    const char* what() const throw() {
		return "Slot penyimpanan tidak mencukupi";
	}
};



#endif