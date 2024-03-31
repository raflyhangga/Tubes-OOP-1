#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
using namespace std;

class Petani : Player
{
private:
public:
    friend ostream &operator<<(ostream &os, const Petani &a);
    friend istream &operator>>(istream &is, Petani &a);
};

#endif