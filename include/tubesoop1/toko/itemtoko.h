#ifndef ITEM_TOKO_H
#define ITEM_TOKO_H
using namespace std;
#include "tubesoop1/resource/resource.h"

class ItemToko {
    private:
        Resource &item;
        int jumlah;
    public:
        // Constructor
        ItemToko(Resource&,int);

        // Copy Constructor
        ItemToko(ItemToko&);
        ItemToko& operator=(ItemToko&);

        // Return ItemToko jumlah
        int getJumlah();

        // Decrement jumlah value
        void decrementJumlah();

        // Increment jumlah value
        void incrementJumlah();

        // Add item toko (Must be the same resource)
        friend ItemToko& operator+= (ItemToko&,ItemToko&);

        // Check if the ItemToko has the same value
        friend bool operator== (ItemToko it1,ItemToko it2);
};


#endif