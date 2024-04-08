#ifndef PRODUCT_VISITORPATTERN_H
#define PRODUCT_VISITORPATTERN_H

// Forward declaration to avoid circular dependency. Its normal for visitor pattern
class EatenElement;
class ProductAnimal;
class ProductFruit;
class ProductMaterial;

// Visitor pattern to avoid dynamic_cast when animal want to eat product but don't know what kind of product it is
class EaterVisitor
{
    public:
        void eat(EatenElement);
        virtual void eat(ProductAnimal&) = 0;
        virtual void eat(ProductFruit&) = 0;
        virtual void eat(ProductMaterial&) = 0;
};

class EatenElement
{
    public:
        virtual void eaten(EaterVisitor &v) = 0;
};

#endif