#include "tubesoop1/resource/creature_exception.h"
NotHarvestableException::NotHarvestableException(const Creature& creature) : message(creature.getName() + " is not harvestable yet.") {}

const char* NotHarvestableException::what() const throw(){
    return message.c_str();
}
