#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
using namespace std;

class Walikota : Player
{
private:
public:
    Walikota(string username,int beratBadan,int uang);
    void pungutPajak();
    friend ostream &operator<<(ostream &os, const Walikota &a);
    friend istream &operator>>(istream &is, Walikota &a);
};

#endif