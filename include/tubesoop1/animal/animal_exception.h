#ifndef ANIMAL_EXCEPTION_H
#define ANIMAL_EXCEPTION_H

#include <exception>
#include <string>
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/product/productvisitorpattern.h"

using namespace std;

class CannotEatException : public exception
{
private:
    const string message;
public:
    CannotEatException(const Animal &animal, const Product &product);
    CannotEatException(string message);
    const char* what() const throw();
};

#endif