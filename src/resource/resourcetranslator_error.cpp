#include "tubesoop1/resource/resourcetranslator_error.h"
FileNotFoundError::FileNotFoundError(const string& _path) : path(_path) {}

const char* FileNotFoundError::what() const throw(){
    string message = "File not found: " + path;
    return message.c_str();
}