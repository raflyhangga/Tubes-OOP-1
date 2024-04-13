#include <tubesoop1/building/bangunan_exception.h>

using namespace std;

const char *RoleWaliKotaException::what() const throw()
{
    return "Bangun Bangunan Gagal, Role Anda Bukan Wali Kota";
}

const char *SlotNotAvailableException::what() const throw()
{
    return "Bangun Bangunan Gagal, Slot Tidak Tersedia";
}

const char *NotEnoughMaterialException::what() const throw()
{
    return "Bangun Bangunan Gagal, Material Tidak Cukup";
}

const char *NotEnoughMoneyException::what() const throw()
{
    return "Bangun Bangunan Gagal, Uang Tidak Cukup";
}