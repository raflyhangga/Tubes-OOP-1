#include "tubesoop1/shop/shop.h"

// Constructor
Shop::Shop(vector<Quantifiable<Resource*>> stock):
    stock(stock)
{}

// Copy Constructor
Shop::Shop(const Shop& other):
    stock(other.stock)
{}

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
        if(!Quantifiable<Resource*>::isInfinite(rsc)){
            os<< "("<<quantity<<")\n";
        }
        else {
            os<<endl;
        }
        idx++;
    }
    return os;
}

vector<Quantifiable<Resource*>>& Shop::getstock(){
    return stock;
}

int Shop::getItem(Quantifiable<Resource*> otherquant){
    int len = stock.size();
    int i = 0;
    for(Quantifiable<Resource*> quant:stock){
        if (*quant.getValue() == *otherquant.getValue()){ // BAHAYA POINTER!
            return i;
        }
        i++;
    }
    throw (ItemShopNotFoundException());
}
int Shop::getItem(Resource &otherrsc){
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
        stock[idx] += otherquant.getQuantity();

        // delete otherquant.getValue();
    }
    catch(ItemShopNotFoundException& e){
        stock.push_back(otherquant);
    }
}

void Shop::buy(Walikota* pl,int idxItem, int quantity){
    Quantifiable<Resource*>* itemShop = &stock[idxItem];
    if(!getStock(pl)[idxItem].second){
        throw(WalikotaShopException());
    }
    buyValidator(pl,idxItem,quantity);
    *itemShop-=quantity;
}

void Shop::buy(Petani* pl,int idxItem, int quantity){
    Quantifiable<Resource*>* itemShop = &stock[idxItem];
    if(!getStock(pl)[idxItem].second){
        throw(PetaniShopException());
    }
    buyValidator(pl,idxItem,quantity);
    *itemShop-=quantity;
}

void Shop::buy(Peternak* pl,int idxItem, int quantity){
    Quantifiable<Resource*>* itemShop = &stock[idxItem];
    if(!getStock(pl)[idxItem].second){
        throw(PeternakShopException());
    }
    buyValidator(pl,idxItem,quantity);
    *itemShop-=quantity;
}

void Shop::buyValidator(Player*pl,int idxItem,int quantity){
    Quantifiable<Resource*>* itemShop = &stock[idxItem];
    if (idxItem < 0 || idxItem > stock.size() - 1)
    {
        throw (BeliOutOfRange());
    }
    if(pl->getInventory().getCountNotFilled() < quantity){
        throw(PenyimpananTidakCukup());
    }
    if((itemShop->getQuantity() - quantity < 0) && (!itemShop->isInfinite())){
        throw(StockTidakCukupShopException());
    }
}

void Shop::cancelBuy(int idxItem, int quantity){
    Quantifiable<Resource*>* itemShop = &stock[idxItem];
    if(!itemShop->isInfinite()){
        *itemShop+=quantity;
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

vector<pair<Quantifiable<Resource*>,bool>> Shop::getStock(Petani* pl){
    vector<pair<Quantifiable<Resource*>,bool>> temp;
    for(Quantifiable<Resource*> rsc: stock){
        pair<Quantifiable<Resource*>,bool> tempPair(rsc,true);
        temp.push_back(tempPair);
    }

    return temp;
}

vector<pair<Quantifiable<Resource*>,bool>> Shop::getStock(Peternak* pl){
    vector<pair<Quantifiable<Resource*>,bool>> temp;
    for(Quantifiable<Resource*> rsc: stock){
        pair<Quantifiable<Resource*>,bool> tempPair(rsc,true);
        temp.push_back(tempPair);
    }

    return temp;
}

vector<pair<Quantifiable<Resource*>,bool>> Shop::getStock(Walikota*){
    vector<pair<Quantifiable<Resource*>,bool>> temp;
    for(Quantifiable<Resource*> rsc: stock){
        try{
            Taker<Building> taker;
            Resource* item = rsc.getValue();
            taker.take(item)->get();
            pair<Quantifiable<Resource*>,bool> tempPair(rsc,false);
            temp.push_back(tempPair);
        } catch(exception& err){
            pair<Quantifiable<Resource*>,bool> tempPair(rsc,true);
            temp.push_back(tempPair);
        }
    }

    return temp;
}

int Shop::countFiniteStock(){
    int count = 0;
    for(Quantifiable<Resource*> rsc: stock){
        if(!rsc.isInfinite()){
            count++;
        }
    }
    return count;
}