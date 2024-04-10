#include "tubesoop1/resourcevisitorpattern/taker.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/resource/resource.h"

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
