#include <tubesoop1/gui/command/cetakpenyimpanan.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/resource/resource.h>

CetakPenyimpanan::CetakPenyimpanan(State& state, MainWindow &window) : Command(state, window) {}

void CetakPenyimpanan::execute(Player *player) {
    window.getTabPenyimpanan().setGrid(&player->getInventory());
}