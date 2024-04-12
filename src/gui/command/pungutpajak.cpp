#include <tubesoop1/gui/command/pungutpajak.h>
#include <tubesoop1/gui/components/messagebox.h>

PungutPajak::PungutPajak(State& state, MainWindow &window) : Command(state, window) {}

void PungutPajak::execute(Petani *petani) {
    MessageBox(&window, "Pungut Pajak", "Anda tidak memiliki hak untuk memungut pajak!").exec();
}
void PungutPajak::execute(Peternak *peternak) {
    MessageBox(&window, "Pungut Pajak", "Anda tidak memiliki hak untuk memungut pajak!").exec();
}
void PungutPajak::execute(Walikota *walikota) {
    string message = "";
    message += "Cring cring cring...\nPajak sudah dipungut!\n\n";

    message += "Berikut adalah detil dari pemungutan pajak:\n";

    // // Disini saldo walikota bertambah
    vector<TaxReport *> taxReports = walikota->pungutPajak(state.getPlayerList(), state.getTotalPlayer());

    int total = 0;
    for (int i = 0; i < taxReports.size(); i++) {
        total += taxReports[i]->getTax();
        message += "   " + to_string(i + 1) + ". " + taxReports[i]->getName() + " - " + taxReports[i]->getRole() + " " + to_string(taxReports[i]->getTax()) + "\n";
    }

    message += "\nNegara mendapatkan pemasukan sebesar " + to_string(total) + " gulden.\n";
    message += "Gunakan dengan baik dan jangan dikorupsi ya!\n";

    MessageBox(&window, "Pungut Pajak", message).exec();
}