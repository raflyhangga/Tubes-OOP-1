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
}

