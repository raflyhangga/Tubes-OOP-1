#ifndef BANGUNAN_EXCEPTION_H
#define BANGUNAN_EXCEPTION_H

using namespace std;
#include <exception>

class RoleWaliKotaException: public exception{
    const char* what() const throw() {
		return "Bangun Bangunan Gagal, Role Anda Bukan Wali Kota";
	}

};
class SlotNotAvailableException: public exception{
    const char* what() const throw() {
		return "Bangun Bangunan Gagal, Slot Tidak Tersedia";
	}
};

class NotEnoughMaterialException: public exception{
    const char* what() const throw() {
        return "Bangun Bangunan Gagal, Material Tidak Cukup";
    }
};

class NotEnoughMoneyException: public exception{
    const char* what() const throw() {
        return "Bangun Bangunan Gagal, Uang Tidak Cukup";
    }
};


#endif