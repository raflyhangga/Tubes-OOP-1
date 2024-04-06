#ifndef WALIKOTA_H
#define WALIKOTA_H

#include <string>
#include "player.h"
using namespace std;

class Walikota : public Player
{
private:
public:
    Walikota(string &username);
    void pungutPajak();


    /**
     * @brief Username must be from constructor. format:
     * <USERNAME> Walikota <BERAT_BADAN> <UANG>
     * <JUMLAH_ITEM_INVENTORY_(M)>
     * <INVENTORY_1>
     * …
     * <INVENTORY M>
     * @param is 
     * @param a 
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const Walikota &a);

    /**
     * @brief Username must be from constructor. format:
     * <BERAT_BADAN> <UANG>
     * <JUMLAH_ITEM_INVENTORY_(M)>
     * <INVENTORY_1>
     * …
     * <INVENTORY M>
     * @param is 
     * @param a 
     * @return istream& 
     */
    friend istream &operator>>(istream &is, Walikota &a);
};

#endif