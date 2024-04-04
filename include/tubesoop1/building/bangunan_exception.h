#ifndef BANGUNAN_EXCEPTION_H
#define BANGUNAN_EXCEPTION_H

using namespace std;
#include <exception>

struct RoleWaliKotaException: public exception{
    const char* what() const throw() {
		return "Bangun Bangunan Gagal, Role Anda Bukan Wali Kota";
	}

};
struct SlotNotAvailableException: public exception{
    const char* what() const throw() {
		return "Bangun Bangunan Gagal, Slot Tidak Tersedia";
	}
};

struct NotEnoughMaterialException: public exception{
    const char* what() const throw() {
        return "Bangun Bangunan Gagal, Material Tidak Cukup";
    }
};

struct NotEnoughMoneyException: public exception{
    const char* what() const throw() {
        return "Bangun Bangunan Gagal, Uang Tidak Cukup";
    }
};


#endif