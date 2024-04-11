#include "tubesoop1/player/walikota.h"
#include <algorithm>

using namespace std;

Walikota::Walikota(string &_username) : Player(_username){};


/**
 * @brief Mengumpulkan pajak dari semua pemain
 * 
 * sudah menambahkan uang ke saldo walikota
 * 
 * @param player: List of Player inside the game
 * @param numberOfPlayer: Number of player inside the game
 * 
 * @return vector<TaxReport> : List of TaxReport from all player excluding the walikota itself
*/
vector<TaxReport *> Walikota::pungutPajak(vector<Player*> &player, int numberOfPlayer)
{
    vector<TaxReport *> taxReports;
    for (int i = 0; i < numberOfPlayer; i++) {

        TaxReport *report = player[i]->bayarPajak(*this);
        if (report->getName() == getUsername()) continue; // self/skip walkota
        taxReports.push_back(report);
    }

    sort(taxReports.begin(), taxReports.end(), [](TaxReport* a, TaxReport* b) {
        if (a->getTax() == b->getTax())
            return a->getName() < b->getName();
        return a->getTax() > b->getTax();
    });

    return taxReports;
}

// visitor pattern
void Walikota::executed(CommanderVisitor &visitor)
{
    visitor.execute(this);
}

TaxReport *Walikota::bayarPajak(Walikota &walikota){
    return new TaxReport(walikota.getUsername(), "Walikota", 0);
}

int Walikota::getKTKP(){
    return 0;
}

bool Walikota::isCanBuy(Resource *){
    return true;
}