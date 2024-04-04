#include "tubesoop1/toko/itemtoko.h"
#include "tubesoop1/toko/Exception.h"

// Constructor
ItemToko::ItemToko(Resource& rsrc,int jumlah):item(rsrc){
    this->jumlah = jumlah;
}

// Copy Constructor
ItemToko::ItemToko(ItemToko& other):item(other.item){
    jumlah = other.jumlah;
}
ItemToko& ItemToko::operator=(ItemToko& other){
    item = other.item;
    jumlah = other.jumlah;
}

// Return ItemToko jumlah
int ItemToko::getJumlah(){
    return this->jumlah;
}

// Decrement jumlah value
void ItemToko::decrementJumlah(){
    jumlah--;
}

// Increment jumlah value
void ItemToko::incrementJumlah(){
    jumlah++;
}

// Add item toko (Must be the same resource)
ItemToko& operator+= (ItemToko& other1,ItemToko& other2){
    if(other1 == other2){
        other1.jumlah += other2.jumlah;
    } else {
        throw(ItemTokoNotEqualException());
    }
    return other1;
}

// Check if the ItemToko has the same value
bool operator== (ItemToko it1,ItemToko it2){
    return it1.item == it2.item; 
}