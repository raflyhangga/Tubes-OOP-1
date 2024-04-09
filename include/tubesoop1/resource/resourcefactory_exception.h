#ifndef RESOURCE_TRANSLATOR_EXCEPTION_H
#define RESOURCE_TRANSLATOR_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

class FileNotFoundException : exception{
    private:
        const string message;
    public:
        FileNotFoundException(const string& path);
        const char* what() const throw();
};

class FolderNotFoundException : exception{
    private:
        const string message;
    public:
        FolderNotFoundException(const string& path);
        const char* what() const throw();
};

#endif