#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
#include "tubesoop1/animal/animal.h"
using namespace std;

class Peternak : Player
{
private:
    Grid<Animal> peternakanHewan;
public:
    Peternak(string username);

    void putPeternakan(Animal h);
    void putPeternakanAt(Hewan h, Location l);

    /**
     * @brief Username must be from constructor. Format:
     * <USERNAME> Peternak <BERAT_BADAN> <UANG>
     * <JUMLAH_ITEM_INVENTORY_(M)>
     * <INVENTORY_1>
     * …
     * <INVENTORY M>
     * <JUMLAH_HEWAN_DI_PETERNAKAN_(K)>
     * <LOKASI_HEWAN_1> <NAMA_HEWAN_1> <BERAT_HEWAN_1>
     * …
     * <LOKASI_HEWAN_K> <NAMA_HEWAN_K> <BERAT_HEWAN_K>
     * @param is 
     * @param a 
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const Peternak &p);

    /**
     * @brief Username must be from constructor. Format:
     * <BERAT_BADAN> <UANG>
     * <JUMLAH_ITEM_INVENTORY_(M)>
     * <INVENTORY_1>
     * …
     * <INVENTORY M>
     * <JUMLAH_HEWAN_DI_PETERNAKAN_(K)>
     * <LOKASI_HEWAN_1> <NAMA_HEWAN_1> <BERAT_HEWAN_1>
     * …
     * <LOKASI_HEWAN_K> <NAMA_HEWAN_K> <BERAT_HEWAN_K>
     * @param is 
     * @param a 
     * @return istream& 
     */
    friend istream &operator>>(istream &is, Peternak &p);
};

#endif