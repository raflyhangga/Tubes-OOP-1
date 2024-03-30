#include "tubesoop1/plant/tanamanladang.h"

TanamanLadang::TanamanLadang(
    tuple<int,int> lokasiTanaman,
    Plant& data,
    int umurTanaman
    ):
    lokasiTanaman(lokasiTanaman),
    data(data),
    umurTanaman(umurTanaman){

}
TanamanLadang::~TanamanLadang(){

}