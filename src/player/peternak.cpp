#include "tubesoop1/player/peternak.h"

Peternak::Peternak(string _username) : Player(_username) {}

istream & operator>>(istream &in, Peternak &a)
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
        string position, name;
        int amount;
        in >> position >> name >> amount;
        // Animal p(name, amount);
        // inventory.setElement(position, p);
    }

    return in;
}

ostream &operator<<(ostream &out, const Peternak &a)
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