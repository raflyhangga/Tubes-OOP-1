#include <tubesoop1/gui/command/cetakladang.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/resource/resource.h>

CetakLadang::CetakLadang(State& state, MainWindow &window) : Command(state, window) {}

void CetakLadang::execute(Peternak *player) {
    window.getTabLadang().clear();
}

void CetakLadang::execute(Petani *player) {
    window.getTabLadang().setGrid(&player->getLadang());
}

void CetakLadang::execute(Walikota *player) {
    window.getTabLadang().clear();
}