#include "tubesoop1/animal/animal_exception.h"

CannotEatException::CannotEatException(const Animal &animal, const Product &product) :
    message(animal.getName() + " cannot eat " + product.getName()) 
{}

const char* CannotEatException::what() const throw(){
    return message.c_str();
}
