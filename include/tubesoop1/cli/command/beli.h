#ifndef BELI_H
#define BELI_H

#include <tubesoop1/cli/command/command.h>
#include <tubesoop1/player/player.h>
#include <tubesoop1/quantifiable/quantifiable.hpp>
#include <tubesoop1/cli/command/beli_exception.h>

class Beli: public Command {
    private:
        Shop &shop;
    public:
        Beli(State&);
        // visitor pattern
        void execute(Player*);

        void checkValidity(Petani*,int);
        void checkValidity(Peternak*,int);
        void checkValidity(Walikota*,int);
        void checkValidity(Player*,int);


        void printStocks(vector<Quantifiable<Resource*>> stock);
};

#endif