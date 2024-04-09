#ifndef RESOURCE_TRANSLATOR_EXCEPTION_H
#define RESOURCE_TRANSLATOR_EXCEPTION_H

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

class FolderNotFoundException : exception{
    private:
        const string path;
    public:
        FolderNotFoundException(const string& _path);
        const char* what() const throw();
};

#endif