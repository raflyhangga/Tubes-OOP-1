#include "tubesoop1/toko/toko.h"

// Constructor
Toko::Toko(vector<Quantifiable<Resource*>> inventory):
    inventory(inventory)
{

}

// Copy Constructor
Toko::Toko(Toko& other):
    inventory(other.inventory)
{

}
Toko& Toko::operator=(Toko& other){
    this->inventory = other.inventory;
    return *this;
}

Quantifiable<Resource*>& Toko::operator[](int idx){
    return inventory[idx];
}
ostream& operator<<(ostream& os,Toko& toko){
    int idx = 1;
    for(Quantifiable<Resource*> rsc: toko.inventory){
        string productName = rsc.getValue()->getName();
        int productPrice = rsc.getValue()->getPrice();
        int quantity = rsc.getQuantity();
        os<<idx<<". ";
        os<<productName;
        os<<" - ";
        os<< productPrice;
        // Check if quantity is unlimited or not
        if(quantity != -1){
            os<< "("<<quantity<<")\n";
        }
        else {
            os<<endl;
        }
        idx++;
    }
    return os;
}

vector<Quantifiable<Resource*>> Toko::getInventory(){
    return inventory;
}

// Mengembalikan indeks lokasi Quantifiable<Resource&> pada inventory
int Toko::getItem(Quantifiable<Resource*> otherquant){
    int len = inventory.size();
    int i = 0;
    for(Quantifiable<Resource*> quant:inventory){
        if (&quant == &otherquant){ // BAHAYA POINTER!
            return i;
        }
        i++;
    }
    throw (ItemTokoNotFoundException());
}
int Toko::getItem(Resource otherrsc){
    int len = inventory.size();
    int i = 0;
    for(Quantifiable<Resource*> quant:inventory){
        if (*quant.getValue() == otherrsc){
            return i;
        }
        i++;
    }
    throw (ItemTokoNotFoundException());
}

// Menghapus suatu Quantifiable<Resource&> dari inventory
void Toko::removeItem(Quantifiable<Resource*> otherquant){
    try{
        int placeToErase = getItem(otherquant)+1;
        inventory.erase(inventory.begin()+placeToErase);
    } catch(exception& err){
        cout<<err.what()<<endl;
    }
}

// Menambahkan suatu Quantifiable<Resource&> dari inventory
void Toko::addItem(Quantifiable<Resource*> otherquant){
    try{
        // If already inside, sum the quantity
        int idx = getItem(otherquant);
        inventory[idx] += otherquant;
    }
    catch(ItemTokoNotFoundException& e){
        inventory.push_back(otherquant);
    }
}

void Toko::buy(int idxItem){
    Quantifiable<Resource*>* itemToko = &inventory[idxItem];
    if(itemToko->getQuantity() > 0){
        *itemToko--;
    }
    else if(itemToko->getQuantity() == 0){
        throw(ItemTokoEmptyException());
    }
}

void Toko::sell(Resource& rsc){
    try{
        int idxItem = getItem(rsc);
        inventory[idxItem]++;
    } catch(ItemTokoNotFoundException& err){
        Resource* rscPtr = &rsc;
        Quantifiable<Resource*> stockBaru(rscPtr,1);
        addItem(stockBaru);
    }
}

void Toko::getProducts(){
    int idx = 1;
    for(Quantifiable<Resource*> rsc: inventory){
        string productName = rsc.getValue()->getName();
        int productPrice = rsc.getValue()->getPrice();
        int quantity = rsc.getQuantity();
        cout<<idx<<". ";
        cout<<productName;
        cout<<" - ";
        cout<< productPrice;
        // Check if quantity is unlimited or not
        if(quantity != -1){
            cout<< "("<<quantity<<")\n";
        }
        else {
            cout<<endl;
        }
        idx++;
    }
}