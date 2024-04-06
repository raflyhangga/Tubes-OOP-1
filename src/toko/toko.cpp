#include "tubesoop1/toko/toko.h"
#include "tubesoop1/toko/Exception.h"

Toko::Toko(){

}
Toko::Toko(vector<Quantifiable<Resource&>> inventory){
    this->inventory = inventory;
}

Toko::Toko(Toko& other){
    this->inventory = other.inventory;
}
Toko& Toko::operator=(Toko& other){
    this->inventory = other.inventory;
}


int Toko::getItem(Quantifiable<Resource&> item){
    int size = inventory.size();
    for(int i=0;i<size;i++){
        if(item == inventory[i]){
            return i;
        }
    }
    throw(ItemTokoNotFoundException());
}


void Toko::removeItem(Quantifiable<Resource&> item){
    int idx = getItem(item);
    inventory.erase(inventory.begin()+idx);
}

void Toko::addItem(Quantifiable<Resource&> item){
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
        inventory[idx]--;
        if(!inventory[idx].getQuantity()){
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
        inventory[idx]--;
    } catch(exception &err){
        cout<<err.what()<<endl;
    }
}
