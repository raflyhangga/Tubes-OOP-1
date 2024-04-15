#include "tubesoop1/cli/command/beli_exception.h"

const char* BeliOutOfRange::what() const throw() {
    return "Barang tidak ditemukan";
}

const char* BarangTidakCukup::what() const throw() {
    return "Kuantitas tidak mencukupi";
}

const char* UangTidakCukup::what() const throw() {
    return "Uang tidak mencukupi";
}

const char* PenyimpananTidakCukup::what() const throw() {
    return "Slot penyimpanan tidak mencukupi";
}
