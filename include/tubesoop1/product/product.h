#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/product/productvisitorpattern.h"

using namespace std;


class Product : public Resource, public EatenElement
{
    protected:
        int addedWeight;

    public:
        Product() = default;
        Product(string code, string name, int price, int addedWeight);
        virtual ~Product();
        int getAddedWeight() const;
        void setAddedWeight(int addedWeight);
        
        // Visitor pattern
        virtual void eaten(EaterVisitor &a) = 0;
        void taken(TakerVisitor* t);
};


class ProductAnimal:public Product{
    public:
        ProductAnimal() = default;
        ProductAnimal(string code, string name, int price,  int addedWeight);
        // Visitor pattern
        void eaten(EaterVisitor &a);

};

class ProductFruit:public Product{
    public:
        ProductFruit() = default;
        ProductFruit(string code, string name, int price, int addedWeight);
        // Visitor pattern
        void eaten(EaterVisitor &a);

};

class ProductMaterial:public Product{
    public:
        ProductMaterial() = default;
        ProductMaterial(string code, string name, int price, int addedWeight);
        // Visitor pattern
        void eaten(EaterVisitor &a);
};

#endif