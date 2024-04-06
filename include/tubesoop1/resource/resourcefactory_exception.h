#ifndef RESOURCE_TRANSLATOR_ERRORH
#define RESOURCE_TRANSLATOR_ERROR_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

class FileNotFoundException : exception{
    private:
        const string path;
    public:
        FileNotFoundException(const string& _path);
        const char* what() const throw();
};

#endif