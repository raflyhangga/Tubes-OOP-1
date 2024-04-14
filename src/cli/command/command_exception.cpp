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

BuildingNotFoundException::BuildingNotFoundException() {

}

const char* BuildingNotFoundException::what() const throw()  {
    return "Kamu tidak punya resep bangunan tersebut!";
}

AnimalNotFoundException::AnimalNotFoundException() : message("Tidak ada hewan di peternakan!"){}

const char* AnimalNotFoundException::what() const throw()  {
    return message.c_str();
}

EmptyInventoryException::EmptyInventoryException() : message("Penyimpanan kosong!"){}

const char* EmptyInventoryException::what() const throw()  {
    return message.c_str();
}

NoFoodException::NoFoodException() : message("Tidak ada makanan di penyimpanan!"){}

const char* NoFoodException::what() const throw()  {
    return message.c_str();
}

NoAnimalInInventoryException::NoAnimalInInventoryException() : message("Tidak ada hewan di penyimpanan!"){}

const char* NoAnimalInInventoryException::what() const throw()  {
    return message.c_str();
}

PeternakanPenuhException::PeternakanPenuhException() : message("Peternakan penuh!"){}

const char* PeternakanPenuhException::what() const throw()  {
    return message.c_str();
}

NoFoodForAnimalException::NoFoodForAnimalException(string message) : message(message){}
const char* NoFoodForAnimalException::what() const throw()  {
    return message.c_str();
}