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
        Product(string code, string name, int addedWeight, int price);
        virtual ~Product();
        int getAddedWeight() const;
        void setAddedWeight(int addedWeight);
        
        // Visitor pattern
        virtual void eaten(EaterVisitor &a) = 0;
        virtual void taken(TakerVisitor* t);
};


class ProductAnimal:public Product{
    public:
        ProductAnimal() = default;
        ProductAnimal(string code, string name, int addedWeight, int price);
        // Visitor pattern
        void eaten(EaterVisitor &a);
        void taken(TakerVisitor* t);

};

class ProductFruit:public Product{
    public:
        ProductFruit() = default;
        ProductFruit(string code, string name, int addedWeight, int price);
        // Visitor pattern
        void eaten(EaterVisitor &a);
        void taken(TakerVisitor* t);

};

class ProductMaterial:public Product{
    public:
        ProductMaterial() = default;
        ProductMaterial(string code, string name, int addedWeight, int price);
        // Visitor pattern
        void eaten(EaterVisitor &a);
        void taken(TakerVisitor* t);
};

#endif