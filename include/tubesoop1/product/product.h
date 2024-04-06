#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include "tubesoop1/resource/resource.h"
// #define DEFAULT_ORIGIN "Unknown"
// #define DEFAULT_ADDED_WEIGHT 0

using namespace std;

class Product : public Resource{
    protected:
        int addedWeight;

    public:
        Product() = default;
        Product(string code, string name, int price, int addedWeight);
        virtual ~Product();
        int getAddedWeight() const;
        void setAddedWeight(int addedWeight);
    
};


class ProductAnimal:public Product{
    public:
        ProductAnimal() = default;
        ProductAnimal(string code, string name, int price,  int addedWeight);


};

class ProductFruit:public Product{
    public:
        ProductFruit() = default;
        ProductFruit(string code, string name, int price, int addedWeight);

};

class ProductMaterial:public Product{
    public:
        ProductMaterial() = default;
        ProductMaterial(string code, string name, int price, int addedWeight);

};

#endif