#include <exception>
#include <tubesoop1/grid/location_exception.hpp>

using namespace std;

LocationException::LocationException(){}

const char* LocationException::what() {
    return "Invalid location input, location format: <Col><Row>, example: A01.";
}

