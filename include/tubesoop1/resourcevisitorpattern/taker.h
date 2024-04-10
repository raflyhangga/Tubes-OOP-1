#ifndef TAKER_H
#define TAKER_H

#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern.h"

template <class T>
class Taker : public TakerVisitor
{
private:
    // Had to resort to this because c++ does not support virtual template
    // normally class Resource will have virtual template that will be overridden by Animal, Product, Plant, and Building
    // to determine the return type.
    // Then we make this class to be: T* take(Resource*); T* take(T*);
    // and calling Taker<Animal>().take(r) will return Animal*. But this is not possible in c++
    // so we have to resort to this: Taker<Animal>().take(r)->get() to get the Animal*
    T* ptr;
public:

    // Make all possible type to give exception by default
    using TakerVisitor::take;

    // This is the main function to be called, will call Resource::taken(TakerVisitor &v)
    Taker* take(Resource*);

    // This is the function that will be called by Resource::taken(TakerVisitor &v). 
    // If the type is wrong, it will throw exception defined by this part: "using TakerVisitor::take;"
    // also make ptr points to the correct type
    void take(T*);

    // Get the pointer
    T* get();
};

// Specialization for Product. This is needed because the children of product will automatically override
// which makes taking Product impossible. So we have to make a specialization for Product
// Again, this is needed because c++ does not support virtual template
template <>
class Taker<Product> : public TakerVisitor
{
private:
    Product* ptr;
public:

    using TakerVisitor::take;
    Taker* take(Resource*);
    void take(Product*);
    Product* get();

    void populate(Product* t);
    void take(ProductMaterial* t);
    void take(ProductFruit* t);
    void take(ProductAnimal* t);
};

#endif