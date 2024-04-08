#include "tubesoop1/player/walikota.h"

Walikota::Walikota(string &_username) : Player(_username){};

void Walikota::pungutPajak()
{
    money += 1000;
}

// visitor pattern
void Walikota::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}

istream & operator>>(istream &in, Walikota &a)
{
    int jumlahItemInventory;
    in >> a.weight >> a.money >> jumlahItemInventory;

    for (int i = 0; i < jumlahItemInventory; i++)
    {
        // Resource r;
    }

    int jumlahTanaman;
    in >> jumlahTanaman;
    for(int i = 0; i < jumlahTanaman; i++)
    {
        // Tanaman t;
    }

    return in;
}

ostream &operator<<(ostream &out, const Walikota &a)
{
    // vector<Resource> inventory = a.getAllAsList();
    // int jumlahItemInventory = inventory.size();
    // out << a.beratBadan << a.uang << endl;
    // out << jumlahItemInventory << endl;
    // for (int i = 0; i < jumlahItemInventory; i++)
    // {
            // out << a[i];
    // }

    int jumlahTanaman;
    // out << jumlahItemInventory << endl;
    // for (int i = 0; i < jumlahItemInventory; i++)
    // {
            // out << a[i];
    // }
    return out;
}