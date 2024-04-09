#include <tubesoop1/cli/command/pungutpajak.h>
#include <tubesoop1/cli/command/command_exception.h>
#include <iostream>

using namespace std;

PungutPajak::PungutPajak(State &state) : Command(state) {}

void PungutPajak::execute(Petani *petani) {
    throw CommandNotAllowedException("PUNGUT_PAJAK");
}
void PungutPajak::execute(Peternak *peternak) {
    throw CommandNotAllowedException("PUNGUT_PAJAK");
}
void PungutPajak::execute(Walikota *walikota) {
    cout << "Cring cring cring...\nPajak sudah dipungut!\n\n";

    cout << "Berikut adalah detil dari pemungutan pajak:\n";

    // Disini saldo walikota bertambah
    vector<TaxReport *> taxReports = walikota->pungutPajak(state.getPlayerList(), state.getTotalPlayer());

    int total = 0;
    for (int i = 0; i < taxReports.size(); i++) {
        total += taxReports[i]->getTax();
        cout << '\t' << i + 1 << ". " << taxReports[i]->getName() << " - " << taxReports[i]->getType() << ' ' << taxReports[i]->getTax() << '\n';
    }

    cout << "\nNegara mendapatkan pemasukan sebesar " << total << " gulden.\n";
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!\n";
}

