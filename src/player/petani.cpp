#include "tubesoop1/player/petani.h"

istream & operator>>(istream &in, Petani &a)
{
    int jumlahItemInventory;
    in >> a.beratBadan >> a.uang >> jumlahItemInventory;

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

ostream &operator<<(ostream &out, const Petani &a)
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