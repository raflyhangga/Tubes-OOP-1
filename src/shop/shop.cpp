#include "tubesoop1/shop/shop.h"

// Constructor
Shop::Shop(vector<Quantifiable<Resource*>> stock):
    stock(stock)
{

}

// Copy Constructor
Shop::Shop(Shop& other):
    stock(other.stock)
{

}
Shop& Shop::operator=(Shop& other){
    this->stock = other.stock;
    return *this;
}

Quantifiable<Resource*>& Shop::operator[](int idx){
    return stock[idx];
}
ostream& operator<<(ostream& os,Shop& Shop){
    int idx = 1;
    for(Quantifiable<Resource*> rsc: Shop.stock){
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

vector<Quantifiable<Resource*>> Shop::getstock(){
    return stock;
}

int Shop::getItem(Quantifiable<Resource*> otherquant){
    int len = stock.size();
    int i = 0;
    for(Quantifiable<Resource*> quant:stock){
        if (&quant == &otherquant){ // BAHAYA POINTER!
            return i;
        }
        i++;
    }
    throw (ItemShopNotFoundException());
}
int Shop::getItem(Resource otherrsc){
    int len = stock.size();
    for(int i=0;i<len;i++){
        if (*stock[i].getValue() == otherrsc){
            return i;
        }
    }
    throw (ItemShopNotFoundException());
}

void Shop::removeItem(Quantifiable<Resource*> otherquant){
    try{
        int placeToErase = getItem(otherquant)+1;
        stock.erase(stock.begin()+placeToErase);
    } catch(exception& err){
        cout<<err.what()<<endl;
    }
}

void Shop::addItem(Quantifiable<Resource*> otherquant){
    try{
        // If already inside, sum the quantity
        int idx = getItem(otherquant);
        stock[idx] += otherquant;
    }
    catch(ItemShopNotFoundException& e){
        stock.push_back(otherquant);
    }
}

void Shop::buy(int idxItem){
    Quantifiable<Resource*>* itemShop = &stock[idxItem];
    if(itemShop->getQuantity() > 0){
        *itemShop--;
    }
    else if(itemShop->getQuantity() == 0){
        throw(ItemShopEmptyException());
    }
}

void Shop::sell(Resource& rsc){
    try{
        int idxItem = getItem(rsc);
        stock[idxItem]++;
    } catch(ItemShopNotFoundException& err){
        Resource* rscPtr = &rsc;
        Quantifiable<Resource*> stockBaru(rscPtr,1);
        addItem(stockBaru);
    }
}

void Shop::getProducts(){
    int idx = 1;
    for(Quantifiable<Resource*> rsc: stock){
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