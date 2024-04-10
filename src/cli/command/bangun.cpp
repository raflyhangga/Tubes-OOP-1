#include "tubesoop1/cli/command/bangun.h"
#include "tubesoop1/cli/command/command_exception.h"
Bangun::Bangun(State& state): Command(state) {}

void Bangun::execute(Petani* petani) {
    throw CommandNotAllowedException("BANGUN");
}
void Bangun::execute(Peternak* peternak) {
    throw CommandNotAllowedException("BANGUN");
}

void Bangun::execute(Walikota* walikota) {
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    
}