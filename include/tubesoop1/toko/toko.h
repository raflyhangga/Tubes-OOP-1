#ifndef TOKO_H
#define TOKO_H
#include "tubesoop1/quantifiable/quantifiable.h"
#include "tubesoop1/player/player.h"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/toko/Exception.h"
#include "tubesoop1/grid/location.h"
#include <vector>
#include <iostream>
using namespace std;

#define UNVALID_IDX -1

class Toko {
    private:
        vector<Quantifiable<Resource*>> inventory; // Elements must be unique
    public:
        Toko() = default;
        Toko(vector<Quantifiable<Resource*>> inventory);        
        Toko(Toko&);
        Toko& operator=(Toko&);
        friend ostream& operator<<(ostream&,Toko&);
        Quantifiable<Resource*>& operator[](int idx);


        /**
         * Mengambilkan inventory dari toko
        */
        vector<Quantifiable<Resource*>> getInventory();

        /**
         * Mengembalikan indeks lokasi Quantifiable<Resource&> pada inventory
         * 
         * @param otherquant Quantifiable yang ingin dicari
         * @return Index pada inventory toko, apabila tidak ada melakukan throw ``ItemTokoNotFoundException()``
        */
        int getItem(Quantifiable<Resource*> otherquant);
        
        /**
         * Mengembalikan indeks lokasi resource pada inventory
         * 
         * @param otherrsc Resource yang ingin dicari
         * @return Index pada inventory toko, apabila tidak ada melakukan throw ``ItemTokoNotFoundException()``
        */
        int getItem(Resource otherrsc);

        /**
         * Menghapus suatu Quantifiable<Resource&> dari inventory.
         * Apabila item tidak ada, akan menangkap ``ItemTokoNotFoundException()`` dan mencetak pesannya
         * 
         * @param otherquant Quantifiable yang dingin dihapus
        */
        void removeItem(Quantifiable<Resource*> otherquant);

        /**
         * Menambahkan suatu Quantifiable<Resource&> dari inventory.
         * Apabila item sudah ada, hanya menambahkan jumlah quantity-nya saja 
         * 
         * @param otherquant Quantifiable yang ingin ditambah
        */
        void addItem(Quantifiable<Resource*> otherquant);

        /**
         * Mengurangi jumlah quantity dari item yang akan dipilih oleh Player.
         * Item yang memiliki kuantitas -1 nilainya akan tetap.
         * Item yang memiliki kuantitas 0 akan melakukan throw ``ItemTokoEmptyException()``
         * 
         * @param idxItem idx dari resource pada inventory toko
         * @note Diasumsikan player bisa membeli seluruh item yang ada di toko.
        */
        void buy(int idxItem);

        /**
         * Menambahi jumlah quantity dari resource yang akan dijual oleh Player.
         * Jika item belum ada di toko, akan dibuatkan katalog baru.
         * 
         * @param rsc resource yang dijual oleh player
         * @note Diasumsikan player bisa membeli seluruh item yang ada di toko.
        */
        void sell(Resource& rsc);

        /**
         * Mencetak isi produk dengan format ``[IDX]. [NAMA PRODUK] - [HARGA] (OPTIONAL[QUANTITY])``
        */
        void getProducts();
};


#endif