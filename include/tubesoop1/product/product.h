#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product {
    protected:
        string kodeHuruf;
        string name;
        string type;
        string origin;
        int addedWeight;
        int price;

    public:
        Product();
        
};


#endif