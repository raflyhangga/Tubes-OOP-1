#include "tubesoop1/resourcevisitorpattern/taker.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/product/product.h"

template <class T>
inline Taker<T>* Taker<T>::take(Resource* t)
{
    t->taken(this);
    return this;
}

template <class T>
inline void Taker<T>::take(T* t)
{
    ptr = t;
}

template <class T>
inline T* Taker<T>::get()
{
    return ptr;
}


// Specialization for Product
inline Taker<Product>* Taker<Product>::take(Resource* t)
{
    t->taken(this);
    return this;
}
inline void Taker<Product>::take(Product* t)
{
    ptr = t;
}
inline Product* Taker<Product>::get()
{
    return ptr;
}
inline void Taker<Product>::populate(Product* t){
    ptr = t;
}
inline void Taker<Product>::take(ProductMaterial* t){
    populate(t);
}
inline void Taker<Product>::take(ProductFruit* t){
    populate(t);
}
inline void Taker<Product>::take(ProductAnimal* t){
    populate(t);
}