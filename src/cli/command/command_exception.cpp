#include <tubesoop1/cli/command/command_exception.h>

CommandNotAllowedException::CommandNotAllowedException(string command)
        : message("Command " + command + " is not allowed for this specific role.") {}

const char* CommandNotAllowedException::what() const throw()  {
    return message.c_str();
}

InvalidInputLocationListException::InvalidInputLocationListException(){}
const char* InvalidInputLocationListException::what() const throw()  {
    return "Input lokasi tidak valid.";
}

CannotPanenException::CannotPanenException(Walikota &walikota) : walikota(walikota) {}
const char* CannotPanenException::what() const throw()  {
    string message = walikota.getUsername() + " (Walikota) tidak bisa melakukan panen.";
    return message.c_str();
}

