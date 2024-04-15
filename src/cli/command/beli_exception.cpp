#include "tubesoop1/cli/command/beli_exception.h"

const char* BarangTidakCukup::what() const throw() {
    return "Kuantitas tidak mencukupi";
}

const char* UangTidakCukup::what() const throw() {
    return "Uang tidak mencukupi";
}

