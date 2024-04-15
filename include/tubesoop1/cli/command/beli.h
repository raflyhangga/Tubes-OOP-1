#ifndef BELI_H
#define BELI_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>
#include <tubesoop1/quantifiable/quantifiable.hpp>
#include <tubesoop1/cli/command/beli_exception.h>
#include <tubesoop1/cli/command/cetakpenyimpanan.h>
#include <tubesoop1/shop/shop_exception.h>
#include <iostream>


class Beli: public Command {
    private:
        Shop &shop;
    public:
        Beli(State&);
        // visitor pattern
        void execute(Walikota*);
        void execute(Petani*);
        void execute(Peternak*);

        int pageSize(vector<pair<Quantifiable<Resource*>,bool>> stok, int currentPage);

        void playerBuy(Player*, int,int);

        bool isBuyable(pair<Quantifiable<Resource*>,bool> pair);
        void validityChecking(vector<pair<Quantifiable<Resource*>,bool>> stok, Player* p,int idxItem,int quantity);

        void clearScreen();
        pair<int,int> welcomeMessage(vector<pair<Quantifiable<Resource*>,bool>>,Player*);
        void printStocks(vector<pair<Quantifiable<Resource*>,bool>> stock);
};

#endif