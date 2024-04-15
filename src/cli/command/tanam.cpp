#include <tubesoop1/cli/command/tanam.h>
#include <tubesoop1/cli/command/command_exception.h>
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include <tubesoop1/grid/griddrawer.hpp>

#include <tubesoop1/cli/command/cetakladang.h>
#include <iostream>

using namespace std;

Tanam::Tanam(State &state) : Command(state) {}

/**
 * Perintah untuk menanam tanaman yang terdapat di penyimpanan ke ladang yang dimiliki oleh pemain.
        1. Pemain memilih tanaman terlebih dahulu dari penyimpanan. Pastikan yang dipilih adalah tanaman. 
        2. Pemain memilih lokasi petak tanah dalam ladang yang akan ditanami. Pastikan petak tanah kosong.
        3. Tanaman yang telah berhasil ditanam akan hilang dari penyimpanan.
    Jika tidak ada tanaman di penyimpanan, perintah tidak dapat dilakukan.
    Jika ladang penuh, perintah tidak dapat dilakukan.

*/
void Tanam::execute(Petani *petani) {
    vector<Plant*> list;
    try {
        list = petani->takeAllFromInventory<Plant>();
    } catch (EmptyInventoryException& e){
        cout << "Kalau gak punya tanaman, apa yang mau ditanam? (Inventory tidak berisi tanaman apapun).\n";
        return;
    }

    if (petani->getLadang().isFull()) throw LadangPenuhException();

    cout << "Pilih tanaman dari penyimpanan\n\n";

    Player *player = state.getCurrentPlayer();

    auto &ladang = petani->getLadang();
    auto &inventory = petani->getInventory();

    // print label and grid penyimpanan
    int total_length = petani->getInventory().getCol()*6 + 1;
    string message = " Penyimpanan ";
    string pad = string((total_length - message.length()) / 2 - 1, '=');
    cout << "   " <<  pad << '[' << message << ']' << pad << endl;

    GridDrawerCLI<Resource*> drawer = GridDrawerCLI<Resource*>(inventory);
    drawer.draw();

    cout << "\nSlot: ";
    Location slot;
    cin >> slot;

    // Ambil tanaman dari penyimpanan
    Plant *plant;
    try {
        plant = player->takeInventory<Plant>(slot);
    } catch (NotTakableException &e) {
        cout << "Lokasi yang dipilih bukan berisi tanaman.\n";
        cout << "Perintah tidak dilanjutkan.\n";
        return;
    }

    // Sukses mengambil tanaman dari penyimpanan
    cout << "\nKamu memilih " << plant->getName() << " dari penyimpanan.\n\n";

    // print label and grid ladang
    CetakLadang printer(state);
    printer.printGrid(ladang);


    // Pilih lokasi tanah di ladang
    cout << "\nPetak tanah: ";
    Location loc; cin >> loc;


    // Tanam tanaman ke ladang
    try {
        ladang.setElement(loc, plant);
    } catch (logic_error &e) {
        cout << "Petak tanah yang dipilih sudah terisi.\n";
        cout << "Perintah gagal dieksekusi.\n";
        return;
    }

    // Berhasil menanam tanaman
    inventory.pop(slot);
    cout << "Cangkul, cangkul, cangkul yang dalam~!\n";
    cout << "Kamu telah menanam " << plant->getName() << " di petak tanah " << loc << ".\n\n";
}
void Tanam::execute(Peternak *peternak) {
    throw CommandNotAllowedException("TANAM");
}
void Tanam::execute(Walikota *walikota) {
    throw CommandNotAllowedException("TANAM");
}
