#include "tubesoop1/player/peternak.h"

Peternak::Peternak(string &_username) : Player(_username) {}

void Peternak::putPeternakan(Animal &h)
{
    peternakan.insert(&h);
}

void Peternak::putPeternakanAt(Animal &h, Location &l)
{
    peternakan.setElement(l, &h);
}

Grid<Animal*>& Peternak::getPeternakan()
{
    return peternakan;
}

TaxReport Peternak::bayarPajak(Walikota &walikota)
{
    int totalTax = 0;
    return TaxReport(username, "Peternak", 0);
}

// visitor pattern
void Peternak::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}