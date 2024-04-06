#ifndef VISITORPATTERN_H
#define VISITORPATTERN_H

// Forward declaration
class ProductAnimal;
class ProductFruit;

class EaterVisitor
{
    public:
        virtual void eat(ProductAnimal&) = 0;
        virtual void eat(ProductFruit&) = 0;
};

class EatenElement
{
    public:
        virtual void eaten(EaterVisitor &v) = 0;
};

#endif