#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class ItemShopNotFoundException : public exception {
public:
    const char *what() const throw() override {
        return "Item is not available in shop";
    }
};

class ItemShopNotEqualException : public exception {
public:
    const char *what() const throw() override {
        return "Both Item is not equal";
    }
};

class ItemShopEmptyException : public exception {
public:
    const char *what() const throw() override {
        return "Stock is empty";
    }
};

class UangTidakCukupException : public exception {
public:
    const char *what() const throw() override {
        return "Insufficient balance";
    }
};

class PetaniException : public exception {
public:
    const char *what() const throw() override {
        return "Farmer Role can't buy this item";
    }
};

class PeternakException : public exception {
public:
    const char *what() const throw() override {
        return "Rancher Role can't buy this item";
    }
};

#endif
