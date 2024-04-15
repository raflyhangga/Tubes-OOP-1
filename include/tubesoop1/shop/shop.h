#ifndef Shop_H
#define Shop_H
#include "tubesoop1/quantifiable/quantifiable.hpp"
#include "tubesoop1/player/player.h"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/shop/shop_exception.h"
#include "tubesoop1/cli/command/beli_exception.h"
#include "tubesoop1/resourcevisitorpattern/taker.hpp"
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

#define UNVALID_IDX -1



class Shop {
    private:
        vector<Quantifiable<Resource*>> stock; // Elements must be unique
    public:
        Shop() = default;
        Shop(vector<Quantifiable<Resource*>> stock);        
        Shop(const Shop&);
        Shop& operator=(Shop&);
        friend ostream& operator<<(ostream&,Shop&);
        Quantifiable<Resource*>& operator[](int idx);


        /**
         * Mengambilkan stock dari Shop
        */
        vector<Quantifiable<Resource*>>& getstock();

        /**
         * Mengembalikan indeks lokasi Quantifiable<Resource&> pada stock
         * 
         * @param otherquant Quantifiable yang ingin dicari
         * @return Index pada stock Shop, apabila tidak ada melakukan throw ``ItemShopNotFoundException()``
        */
        int getItem(Quantifiable<Resource*> otherquant);
        
        /**
         * Mengembalikan indeks lokasi resource pada stock
         * 
         * @param otherrsc Resource yang ingin dicari
         * @return Index pada stock Shop, apabila tidak ada melakukan throw ``ItemShopNotFoundException()``
        */
        int getItem(Resource &otherrsc);

        /**
         * Menghapus suatu Quantifiable<Resource&> dari stock.
         * Apabila item tidak ada, akan menangkap ``ItemShopNotFoundException()`` dan mencetak pesannya
         * 
         * @param otherquant Quantifiable yang dingin dihapus
        */
        void removeItem(Quantifiable<Resource*> otherquant);

        /**
         * Menambahkan suatu Quantifiable<Resource&> dari stock.
         * Apabila item sudah ada, hanya menambahkan jumlah quantity-nya saja 
         * 
         * @param otherquant Quantifiable yang ingin ditambah
        */
        void addItem(Quantifiable<Resource*> otherquant);

        /**
         * Mengurangi jumlah quantity dari item yang akan dipilih oleh Player.
         * Item yang memiliki kuantitas -1 nilainya akan tetap.
         * Item yang memiliki kuantitas 0 akan melakukan throw ``ItemShopEmptyException()``
         * 
         * @param idxItem idx dari resource pada stock Shop
         * @param quantity banyak item yang ingin dibeli
         * @note Diasumsikan player bisa membeli seluruh item yang ada di Shop.
        */
        void buy(Walikota* pl,int idxItem, int quantity);

        /**
         * Mengurangi jumlah quantity dari item yang akan dipilih oleh Player.
         * Item yang memiliki kuantitas -1 nilainya akan tetap.
         * Item yang memiliki kuantitas 0 akan melakukan throw ``ItemShopEmptyException()``
         * 
         * @param idxItem idx dari resource pada stock Shop
         * @param quantity banyak item yang ingin dibeli
         * @note Diasumsikan player bisa membeli seluruh item yang ada di Shop.
        */
        void buy(Petani* pl,int idxItem, int quantity);

        /**
         * Mengurangi jumlah quantity dari item yang akan dipilih oleh Player.
         * Item yang memiliki kuantitas -1 nilainya akan tetap.
         * Item yang memiliki kuantitas 0 akan melakukan throw ``ItemShopEmptyException()``
         * 
         * @param idxItem idx dari resource pada stock Shop
         * @param quantity banyak item yang ingin dibeli
         * @note Diasumsikan player bisa membeli seluruh item yang ada di Shop.
        */
        void buy(Peternak* pl,int idxItem, int quantity);

        /**
         * Mengecek apakah item bisa dibeli
         * 
         * @param pair item beserta status pembeliannya
        */
        static bool isBuyable(pair<Quantifiable<Resource*>,bool> pair);

        /**
         * Membatalkan pembelian dari Player.
         * Item yang memiliki kuantitas -1 nilainya akan tetap.
         * Item yang memiliki kuantitas 0 akan melakukan throw ``ItemShopEmptyException()``
         * 
         * @param idxItem idx dari resource pada stock Shop
         * @param quantity banyak item yang ingin dibeli
         * @note Diasumsikan player bisa membeli seluruh item yang ada di Shop.
        */
        void cancelBuy(int idxItem, int quantity);

        /**
         * Menambahi jumlah quantity dari resource yang akan dijual oleh Player.
         * Jika item belum ada di Shop, akan dibuatkan katalog baru.
         * 
         * @param rsc resource yang dijual oleh player
         * @note Diasumsikan player bisa membeli seluruh item yang ada di Shop.
        */
        void sell(Resource& rsc);

        /**
         * Mengembalikan stock yang dapat dibeli oleh petani
         * 
         * @return ``vector<pair<Quantifiable<Resource*>,bool>>`` stok petani dengan bool apakah item bisa dibeli atau tidak
        */
        vector<pair<Quantifiable<Resource*>,bool>> getStock(Petani*);

        /**
         * Mengembalikan stock yang dapat dibeli oleh peternak
         * 
         * @return ``vector<pair<Quantifiable<Resource*>,bool>>`` stok peternak dengan bool apakah item bisa dibeli atau tidak
        */
        vector<pair<Quantifiable<Resource*>,bool>> getStock(Peternak*);

        /**
         * Mengembalikan stock yang dapat dibeli oleh walikota
         * 
         * @return ``vector<pair<Quantifiable<Resource*>,bool>>`` stok walikota dengan bool apakah item bisa dibeli atau tidak
        */
        vector<pair<Quantifiable<Resource*>,bool>> getStock(Walikota*);

};


#endif