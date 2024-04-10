#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"

NotTakableException::NotTakableException(const Resource& r) : message(r.getName() + " cannot taken by this type.") {}

const char* NotTakableException::what() const throw(){
    return message.c_str();
}
