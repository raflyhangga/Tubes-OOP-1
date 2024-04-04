#ifndef TOKO_H
#define TOKO_H
#include "tubesoop1/toko/itemtoko.h"
#include "tubesoop1/player/player.h"
#include "tubesoop1/resource/resource.h"
#include <vector>
using namespace std;

#define UNVALID_IDX -1

class Toko {
    private:
        // Elements must be unique
        vector<ItemToko> inventory;
    public:
        // Constructor
        Toko();
        Toko(vector<ItemToko> inventory);
        
        // Copy Constructor
        Toko(Toko&);
        Toko& operator=(Toko&);

        // Mengembalikan indeks lokasi ItemToko pada inventory
        int getItem(ItemToko);
        int getItem(Resource);

        // Menghapus suatu ItemToko dari inventory
        void removeItem(ItemToko);

        // Menambahkan suatu ItemToko dari inventory
        void addItem(ItemToko);
        void buy(Player&,Resource);
        void sell(Player&,Resource);
};


#endif