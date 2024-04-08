#include "tubesoop1/player/petani.h"

Petani::Petani(string &_username) : Player(_username) {}

void Petani::putLadang(Plant &p)
{
    ladang.insert(&p);
}

void Petani::putLadangAt(Plant &p, Location &l)
{
    ladang.setElement(l, &p);
}

Grid<Plant*>& Petani::getLadang()
{
    return ladang;
}

// visitor pattern
void Petani::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}

istream & operator>>(istream &in, Petani &a)
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