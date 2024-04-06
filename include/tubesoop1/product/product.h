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
        string origin;
        int addedWeight;

    public:
        Product() = default;
        Product(string id, string code, string name, int price, string origin, int addedWeight);
        
        string getOrigin() const;
        int getAddedWeight() const;
        void setOrigin(string origin);
        void setAddedWeight(int addedWeight);
        friend bool operator==(const Product &p1, const Product &p2);
};


class ProductAnimal:public Product{
    public:
        ProductAnimal() = default;
        ProductAnimal(string id, string code, string name, int price, string origin, int addedWeight);


};

class ProductFruit:public Product{
    public:
        ProductFruit() = default;
        ProductFruit(string id, string code, string name, int price, string origin, int addedWeight);

};

class ProductMaterial:public Product{
    public:
        ProductMaterial() = default;
        ProductMaterial(string id, string code, string name, int price, string origin, int addedWeight);

};

#endif