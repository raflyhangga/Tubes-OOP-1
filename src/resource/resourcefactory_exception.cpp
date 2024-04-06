#include "tubesoop1/resource/resourcefactory_exception.h"
FileNotFoundException::FileNotFoundException(const string& _path) : path(_path) {}

const char* FileNotFoundException::what() const throw(){
    string message = "File not found: " + path;
    return message.c_str();
}