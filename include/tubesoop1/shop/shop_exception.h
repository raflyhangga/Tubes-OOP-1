#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class BuyingFromShopNotSuccesfullException : public exception {
    private:
        string message;
    public:
        BuyingFromShopNotSuccesfullException();
        const char* what() const throw();
};

class ItemShopNotFoundException : public exception {
    private:
        string message;
    public:
        ItemShopNotFoundException();
        const char* what() const throw();
};

class ItemShopNotEqualException : public exception {
    private:
        string message;
    public:
        ItemShopNotEqualException();
        const char* what() const throw();
};

class ItemShopEmptyException : public exception {
    private:
        string message;
    public:
        ItemShopEmptyException();
        const char *what() const throw();
};

class UangTidakCukupShopException : public exception {
    private:
        string message;
    public:
        UangTidakCukupShopException();
        const char *what() const throw();
};

class StockTidakCukupShopException : public exception {
    private:
        string message;
    public:
        StockTidakCukupShopException();
        const char *what() const throw();
};

class PetaniShopException : public exception {
    private:
        string message;
    public:
        PetaniShopException();
        const char *what() const throw();
};

class PeternakShopException : public exception {
    private:
        string message;
    public:
        PeternakShopException();
        const char *what() const throw();
};

class WalikotaShopException : public exception {
    private:
        string message;
    public:
        WalikotaShopException();
        const char *what() const throw();
};

class BeliOutOfRange: public exception{
	public:
		const char* what() const throw();
};

class PenyimpananTidakCukup: public exception{
    public:
		const char* what() const throw();
};

#endif
