#include <tubesoop1/cli/command/command_exception.h>

CommandNotAllowedException::CommandNotAllowedException(string command)
        : message("Command " + command + " is not allowed for this specific role.") {}

const char* CommandNotAllowedException::what() const throw()  {
    return message.c_str();
}

CommandNotExistException::CommandNotExistException(string command)
        : message("Perintah '" + command + "' tidak tersedia! Gunakan perintah 'HELP' untuk melihat daftar perintah.") {}

const char* CommandNotExistException::what() const throw()  {
    return message.c_str();
}

InvalidInputLocationListException::InvalidInputLocationListException(){}
const char* InvalidInputLocationListException::what() const throw()  {
    return "Input lokasi tidak valid.";
}

CannotPanenException::CannotPanenException(Player &player) : message((player.getUsername() + " (Walikota) tidak bisa melakukan panen.")) {}
const char* CannotPanenException::what() const throw()  {
    return message.c_str();
}

