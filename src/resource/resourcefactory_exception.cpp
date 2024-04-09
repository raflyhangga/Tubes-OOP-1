#include "tubesoop1/resource/resourcefactory_exception.h"
FileNotFoundException::FileNotFoundException(const string& path) : message("File not found: " + path) {}

const char* FileNotFoundException::what() const throw(){
    return message.c_str();
}

FolderNotFoundException::FolderNotFoundException(const string& path) : message("Folder not found: " + path) {}

const char* FolderNotFoundException::what() const throw(){
    return message.c_str();
}