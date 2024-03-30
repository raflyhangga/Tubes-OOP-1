#ifndef HEWANPETERNAKAN_H
#define HEWANPETERNAKAN_H

#include "animal/animal.h"
#include <tuple>
using namespace std;

#define DEFAULT_BERAT 0

/**
 *  `HewanPeternakan` digunakan pada `Peternak` sebagai suatu objek
 *  untuk menyimpan `data` hewan beserta `lokasiHewan` dan `beratHewan`.
*/
class HewanPeternakan {
    private:
        tuple<int,int> lokasiHewan;
        Animal &data;
        int beratHewan;
    public:
    HewanPeternakan(tuple<int,int>,Animal&,int);
    ~HewanPeternakan();


};


#endif