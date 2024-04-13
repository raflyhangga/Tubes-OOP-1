#include <exception>
#include <tubesoop1/grid/location_exception.h>

using namespace std;

LocationException::LocationException(){}

const char* LocationException::what() const throw() {
    return "Invalid location input, location format: <Col><Row>, example: A01.";
}

