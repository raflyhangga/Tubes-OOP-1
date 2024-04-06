#ifndef PETANI_H
#define PETANI_H

#include <string>
#include "player.h"
#include "tubesoop1/plant/plant.h"
#include "tubesoop1/player/petani.h"
using namespace std;

class Petani : public Player
{
private:
    Grid<Plant*> ladang;
public:
    Petani(string &username);

    void putLadang(Plant &p);
    void putLadangAt(Plant &p, Location &l);


    /**
     * @brief Username must be from constructor. Format:
     * <USERNAME> Petani <BERAT_BADAN> <UANG>
     * <JUMLAH_ITEM_INVENTORY_(M)>
     * <INVENTORY_1>
     * …
     * <INVENTORY M>
     * <JUMLAH_TANAMAN_DI_LADANG_(K)>
     * <LOKASI_TANAMAN_1> <NAMA_TANAMAN_1> <UMUR_TANAMAN_1>
     * …
     * <LOKASI_TANAMAN_K> <NAMA_TANAMAN_K> <UMUR_TANAMAN_K>
     * 
     * @param is 
     * @param a 
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const Petani &a);
    
    /**
     * @brief Username must be from constructor. Format:
     * <BERAT_BADAN> <UANG>
     * <JUMLAH_ITEM_INVENTORY_(M)>
     * <INVENTORY_1>
     * …
     * <INVENTORY M>
     * <JUMLAH_TANAMAN_DI_LADANG_(K)>
     * <LOKASI_TANAMAN_1> <NAMA_TANAMAN_1> <UMUR_TANAMAN_1>
     * …
     * <LOKASI_TANAMAN_K> <NAMA_TANAMAN_K> <UMUR_TANAMAN_K>
     * 
     * @param is 
     * @param a 
     * @return istream& 
     */
    friend istream &operator>>(istream &is, Petani &a);
};

#endif