#ifndef BELI_EXCEPTION_H
#define BELI_EXCEPTION_H

using namespace std;
#include <exception>

class BarangTidakCukup: public exception{
	public:
		const char* what() const throw();
};

class UangTidakCukup: public exception{
	public:
		const char* what() const throw();
};


#endif