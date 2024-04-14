#include "tubesoop1/shop/shop_exception.h"

BuyingFromShopNotSuccesfullException::BuyingFromShopNotSuccesfullException():message("Purchasement failed."){}
const char* BuyingFromShopNotSuccesfullException::what() const throw(){
    return message.c_str();
}

ItemShopNotFoundException::ItemShopNotFoundException():message("Item is not available in shop"){}
const char* ItemShopNotFoundException::what() const throw(){
    return message.c_str();
}

ItemShopNotEqualException::ItemShopNotEqualException():message("Both Item is not equal"){}
const char* ItemShopNotEqualException::what() const throw(){
    return message.c_str();
}

ItemShopEmptyException::ItemShopEmptyException():message("Stock is empty"){}
const char *ItemShopEmptyException::what() const throw(){
    return message.c_str();
}

UangTidakCukupShopException::UangTidakCukupShopException():message("Insufficient balance"){}
const char *UangTidakCukupShopException::what() const throw(){
    return message.c_str();
}

PetaniShopException::PetaniShopException():message("Farmer Role can't buy this item"){}
const char *PetaniShopException::what() const throw(){
    return message.c_str();
}

PeternakShopException::PeternakShopException():message("Rancher Role can't buy this item"){}
const char *PeternakShopException::what() const throw(){
    return message.c_str();
}

WalikotaShopException::WalikotaShopException():message("Mayor can't buy this item"){}
const char *WalikotaShopException::what() const throw(){
    return message.c_str();
}