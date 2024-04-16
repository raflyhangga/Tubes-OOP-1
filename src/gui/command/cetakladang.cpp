#include <tubesoop1/gui/command/cetakladang.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/resource/resource.h>
#include <set>

CetakLadang::CetakLadang(State& state, MainWindow &window) : Command(state, window) {}

void CetakLadang::execute(Peternak *player) {
    window.getTabLadang().showError("Hanya petani yang bisa melihat ladang!");
    window.getTabLadangLabel().setText("");
}

void CetakLadang::execute(Petani *player) {
    window.getTabLadang().setGrid(&player->getLadang());
    window.getTabLadangLabel().setText(
        QString::fromStdString(getInfo(player->getLadang()))
    );
}

void CetakLadang::execute(Walikota *player) {
    window.getTabLadang().showError("Hanya petani yang bisa melihat ladang!");
    window.getTabLadangLabel().setText("");
}

string CetakLadang::getInfo(Grid<Plant *> &ladang){
    string info = "";
    set<pair<string, string>> codesAndNames;
    for (const auto &loc: ladang) {
        Plant *plant = ladang.getElement(loc);
        codesAndNames.insert({plant->getCode(), plant->getName()});
    }

    for (auto &[code, name]: codesAndNames) {
        info += "- " + code + ": " + formatName(name) + '\n';
    }
    return info;
}
