#include "tubesoop1/animal/hewanpeternakan.h"

HewanPeternakan::HewanPeternakan(
    tuple<int,int> lokasiHewan,
    Animal &data,
    int beratHewan
    ):
    lokasiHewan(lokasiHewan),
    data(data),
    beratHewan(beratHewan){

}

HewanPeternakan::~HewanPeternakan(){

}