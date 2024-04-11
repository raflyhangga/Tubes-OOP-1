#include <tubesoop1/gui/command/cetakpeternakan.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/resource/resource.h>

CetakPeternakan::CetakPeternakan(State& state, MainWindow &window) : Command(state, window) {}

void CetakPeternakan::execute(Peternak *player) {
    window.getTabPeternakan().setGrid(&player->getPeternakan());
}

void CetakPeternakan::execute(Petani *player) {
    window.getTabPeternakan().clear();
}

void CetakPeternakan::execute(Walikota *player) {
    window.getTabPeternakan().clear();
}