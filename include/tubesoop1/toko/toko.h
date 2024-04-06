#ifndef TOKO_H
#define TOKO_H
#include "tubesoop1/quantifiable/quantifiable.h"
#include "tubesoop1/player/player.h"
#include "tubesoop1/resource/resource.h"
#include <vector>
using namespace std;

#define UNVALID_IDX -1

class Toko {
    private:
        // Elements must be unique
        vector<Quantifiable<Resource&>> inventory;
    public:
        // Constructor
        Toko();
        Toko(vector<Quantifiable<Resource&>> inventory);
        
        // Copy Constructor
        Toko(Toko&);
        Toko& operator=(Toko&);

        // Mengembalikan indeks lokasi Quantifiable<Resource&> pada inventory
        int getItem(Quantifiable<Resource&>);
        int getItem(Resource);

        // Menghapus suatu Quantifiable<Resource&> dari inventory
        void removeItem(Quantifiable<Resource&>);

        // Menambahkan suatu Quantifiable<Resource&> dari inventory
        void addItem(Quantifiable<Resource&>);
        void buy(Player&,Resource);
        void sell(Player&,Resource);
};


#endif