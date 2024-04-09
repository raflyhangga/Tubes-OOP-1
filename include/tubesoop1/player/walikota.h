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
    TaxReport bayarPajak(Walikota &walikota);
    int getKTKP();

    // visitor pattern
    void executed(CommanderVisitor&);
};

#endif