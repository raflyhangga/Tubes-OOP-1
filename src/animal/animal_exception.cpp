#include "tubesoop1/animal/animal_exception.h"

CannotEatException::CannotEatException(const Animal &animal, const Product &product) :
    message(animal.getName() + " tidak bisa makan " + product.getName()) 
{}

CannotEatException::CannotEatException(string message) : message(message) {}

const char* CannotEatException::what() const throw(){
    return message.c_str();
}
