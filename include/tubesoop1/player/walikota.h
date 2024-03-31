#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
using namespace std;

class Walikota : Player
{
private:
public:
    void pungutPajak();
    friend ostream &operator<<(ostream &os, const Walikota &a);
    friend istream &operator>>(istream &is, Walikota &a);
};

#endif