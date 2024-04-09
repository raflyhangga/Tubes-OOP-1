#include "tubesoop1/cli/command/makan.h"
#include "tubesoop1/cli/command/cetakpenyimpanan.h"
Makan::Makan(State &state) : Command(state) {}

void Makan::execute(Player* player){
    // TO DO validasi penyimpanan apakah ada makanan/kosong

    Grid<Resource*> &inventory = state.getCurrentPlayer()->getInventory();
    Player* currPlayer = state.getCurrentPlayer();
    cout << "Pilih makanan dari penyimpanan" << endl;
    CetakPenyimpanan(state).print(player->getInventory());

    cout << "Slot: ";
    Location loc;
    cin >> loc;
    Product *food = dynamic_cast<Product*>(inventory.getElement(loc));
    inventory.pop(loc);
    currPlayer->eat(*food);

    cout << "Kenyang gan, berat badan naik " << food->getAddedWeight() << " kg." <<  endl;
    // validasi dll bloman

    // to do, check if location is valid (is food, is not empty, etc)



}