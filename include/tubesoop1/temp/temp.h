#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Temp
{
private:
public:
    friend ostream &operator<<(ostream &os, const Temp &a);
    friend istream &operator>>(istream &is, Temp &a);
};

#endif