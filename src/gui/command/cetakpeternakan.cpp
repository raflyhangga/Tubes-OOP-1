#include <tubesoop1/gui/command/cetakpeternakan.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/resource/resource.h>
#include <set>
#include <QString>

CetakPeternakan::CetakPeternakan(State& state, MainWindow &window) : Command(state, window) {}

void CetakPeternakan::execute(Peternak *player) {
    window.getTabPeternakan().setGrid(&player->getPeternakan());
    window.getTabPeternakanLabel().setText(
        QString::fromStdString(getInfo(player->getPeternakan()))
    );
}

void CetakPeternakan::execute(Petani *player) {
    window.getTabPeternakan().showError("Hanya peternak yang bisa melihat peternakan!");
    window.getTabPeternakanLabel().setText("");
}    

void CetakPeternakan::execute(Walikota *player) {
    window.getTabPeternakan().showError("Hanya peternak yang bisa melihat peternakan!");
    window.getTabPeternakanLabel().setText("");
}


string CetakPeternakan::getInfo(Grid<Animal *> &peternakan){
    string info = "";
    set<pair<string, string>> codesAndNames;
    for (const auto &loc: peternakan) {
        Animal *animal = peternakan.getElement(loc);
        codesAndNames.insert({animal->getCode(), animal->getName()});
    }
    for (auto &[code, name]: codesAndNames) {
        info += "- " + code + ": " + formatName(name) + '\n';
    }
    return info;
}