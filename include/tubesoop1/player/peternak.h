#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
using namespace std;

class Peternak : Player
{
private:
public:
    friend ostream &operator<<(ostream &os, const Peternak &a);
    friend istream &operator>>(istream &is, Peternak &a);
};

#endif