#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include <exception>
#include <iostream>
#include "tubesoop1/player/player.h"
using namespace std;

class CommandNotAllowedException: public exception {
    private:
        string message;
    public:
        CommandNotAllowedException(string command);
        const char* what() const throw();
};

class CommandNotExistException: public exception {
    private:
        string message;
    public:
        CommandNotExistException(string command);
        const char* what() const throw();
};

class InvalidInputLocationListException: public exception {
    public:
        InvalidInputLocationListException();
        const char* what() const throw();
};

class BuildingNotFoundException: public exception {
    public:
        BuildingNotFoundException();
        const char* what() const throw();
};

class AnimalNotFoundException: public exception {
    private:
        string message;
    public:
        AnimalNotFoundException();
        const char* what() const throw();
};

class EmptyInventoryException: public exception {
    private:
        string message;
    public:
        EmptyInventoryException();
        const char* what() const throw();
};

class NoFoodException: public exception {
    private:
        string message;
    public:
        NoFoodException();
        const char* what() const throw();
};

class NoAnimalInInventoryException: public exception {
    private:
        string message;
    public:
        NoAnimalInInventoryException();
        const char* what() const throw();
};

class PeternakanPenuhException: public exception {
    private:
        string message;
    public:
        PeternakanPenuhException();
        const char* what() const throw();
};

class NoFoodForAnimalException: public exception {
    private:
        string message;
    public:
        NoFoodForAnimalException(string message);
        const char* what() const throw();
};

class NoHarvestablePlantException : public exception {
    private:
        string message;
    public:
        NoHarvestablePlantException();
        const char* what() const throw();
};

class NoHarvestableAnimalException : public exception {
    private:
        string message;
    public:
        NoHarvestableAnimalException();
        const char* what() const throw();
};

class NotFoundException : public exception {
    private:
        string message;
    public:
        NotFoundException(string message);
        const char* what() const throw();
};
#endif