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
    vector<TaxReport *> pungutPajak(vector<Player*> &p, int numberOfPlayer);
    TaxReport *bayarPajak(Walikota &walikota);
    int getKTKP();

    bool isCanBuy(Resource*);
    // visitor pattern
    void executed(CommanderVisitor&);

};

#endif