#include "tubesoop1/player/walikota.h"

Walikota::Walikota(string &_username) : Player(_username){};

void Walikota::pungutPajak()
{
    money += 1000;
}

// visitor pattern
void Walikota::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}

TaxReport Walikota::bayarPajak(Walikota &walikota){
    return TaxReport("", "", 0);
}

int Walikota::getKTKP(){
    return 0;
}