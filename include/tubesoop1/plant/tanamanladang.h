#ifndef TANAMANLDANG_H
#define TANAMANLDANG_H

#include "plant/plant.h"
#include <tuple>
using namespace std;

/**
 *  `TanamanLadang` digunakan pada `Petani` sebagai suatu objek
 *  untuk menyimpan `data` tanaman beserta `lokasiTanaman` dan `umurTanaman`.
*/
class TanamanLadang {
    private:
        tuple<int,int> lokasiTanaman;
        Plant &data;
        int umurTanaman;
    public:
    TanamanLadang(tuple<int,int>,Plant&,int);
    ~TanamanLadang();


};


#endif