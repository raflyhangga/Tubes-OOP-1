#include "tubesoop1/toko/toko.h"
#include "tubesoop1/toko/Exception.h"

Toko::Toko(){

}
Toko::Toko(vector<ItemToko> inventory){
    this->inventory = inventory;
}

Toko::Toko(Toko& other){
    this->inventory = other.inventory;
}
Toko& Toko::operator=(Toko& other){
    this->inventory = other.inventory;
}


int Toko::getItem(ItemToko item){
    int size = inventory.size();
    for(int i=0;i<size;i++){
        if(item == inventory[i]){
            return i;
        }
    }
    throw(ItemTokoNotFoundException());
}


void Toko::removeItem(ItemToko item){
    int idx = getItem(item);
    inventory.erase(inventory.begin()+idx);
}

void Toko::addItem(ItemToko item){
    try
    {
        int idx = getItem(item);
        inventory[idx] += item;
    }
    catch(ItemTokoNotFoundException err)
    {
        inventory.push_back(item);
    }
    
}

void Toko::buy(Player& pl, Resource rsc){
    try{
        int idx = getItem(rsc);
        pl.putInventory(rsc);
        inventory[idx].decrementJumlah();
        if(!inventory[idx].getJumlah()){
            removeItem(inventory[idx]);
        }
    } catch(exception &err){
        cout<<err.what()<<endl;
    }
}

void Toko::sell(Player& pl, Resource rsc){
    try{
        int idx = getItem(rsc);
        pl.putInventory(rsc);
        inventory[idx].decrementJumlah();
    } catch(exception &err){
        cout<<err.what()<<endl;
    }
}
