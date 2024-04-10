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
    using TakerVisitor::take;
    Taker* take(Resource*);
    void take(T*);
    T* get();
};

#endif