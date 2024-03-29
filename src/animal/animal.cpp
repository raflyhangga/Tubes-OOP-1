#include "tubesoop1/animal/animal.h"

istream &operator>>(istream &is, Animal &p)
{
    return is;
}

ostream &operator<<(ostream &os, const Animal &p)
{
    return os;
}