#ifndef BELI_H
#define BELI_H

#include <tubesoop1/player/player.h>
#include <tubesoop1/quantifiable/quantifiable.hpp>
#include <tubesoop1/player/player.h>
#include <tubesoop1/player/petani.h>
#include <tubesoop1/player/peternak.h>
#include <tubesoop1/player/walikota.h>
#include <tubesoop1/state/state.h>
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/components/mainwindow.h>
#include <QVector>
#include <utility>

class Beli: public Command {
    private:
        Shop &shop;
    public:
        Beli(State&, MainWindow&);
        // visitor pattern
        void execute(Walikota*);
        void execute(Petani*);
        void execute(Peternak*);

        bool isBuyable(pair<Quantifiable<Resource*>,bool> pair);
        void validityChecking(vector<pair<Quantifiable<Resource*>,bool>> stok, Player* p,int idxItem,int quantity);

        QVector<pair<string, string>> getChoices(vector<pair<Quantifiable<Resource*>,bool>>&);
        void handleCurrentPlayer(Player* player, vector<pair<Quantifiable<Resource*>,bool>> &stockList);
};

#endif