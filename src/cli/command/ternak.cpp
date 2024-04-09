#include "tubesoop1/cli/command/ternak.h"


Ternak::Ternak(State &state) : Command(state) {

}   

void Ternak::execute(Peternak *peternak) {
    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();

    Grid<Animal*> &peternakan = peternak->getPeternakan();

    // TODO : CEK DI PENYIMPANAN ADA HEWAN
    if(peternakan.isFull()){
        throw("Peternakan Penuh!");
    }
 
    cout << "Pilih hewan dari penyimpanan" << endl;
    CetakPenyimpanan(state).print(inventory);
    // CetakPenyimpanan::print(inventory);
    cout << "\n";
    cout << "Slot: ";
    Location loc;
    cin >> loc;
    // TO DO, CHECK IF LOCATION IS VALID (is animal, is not empty, etc)

    // rest not yet implemented, waiting for cetak peternakan
}

void Ternak::execute(Petani *petani) {
    throw CommandNotAllowedException("TERNAK");
}

void Ternak::execute(Walikota *walikota) {
    throw CommandNotAllowedException("TERNAK");
}