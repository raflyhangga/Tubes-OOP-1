#include <tubesoop1/gui/command/tanam.h>
#include <tubesoop1/gui/command/command_exception.h>
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include <tubesoop1/grid/griddrawer.hpp>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/gui/components/dialog.h>
#include <QVBoxLayout>
#include <QLabel>
#include "tubesoop1/gui/components/gridview.hpp"

using namespace std;

Tanam::Tanam(State &state, MainWindow &window) : Command(state, window) {}

/**
 * Perintah untuk menanam tanaman yang terdapat di penyimpanan ke ladang yang dimiliki oleh pemain.
        1. Pemain memilih tanaman terlebih dahulu dari penyimpanan. Pastikan yang dipilih adalah tanaman. 
        2. Pemain memilih lokasi petak tanah dalam ladang yang akan ditanami. Pastikan petak tanah kosong.
        3. Tanaman yang telah berhasil ditanam akan hilang dari penyimpanan.
    Jika tidak ada tanaman di penyimpanan, perintah tidak dapat dilakukan.
    Jika ladang penuh, perintah tidak dapat dilakukan.

*/
void Tanam::execute(Petani *petani) {
    Dialog dialog(&window);

    QVBoxLayout vLayout;
    dialog.setLayout(&vLayout);
    QLabel label("Pilih tanaman dari penyimpanan");
    vLayout.addWidget(&label);

    Player *player = state.getCurrentPlayer();
    auto &ladang = petani->getLadang();
    auto &inventory = petani->getInventory();
    
    GridView<Resource*> inventoryWidget;
    inventoryWidget.setMinimumSize(QSize(960, 540));
    inventoryWidget.setGrid(&player->getInventory());
    inventoryWidget.setEnabled(true);
    vLayout.addWidget(&inventoryWidget);

    inventoryWidget.connect(&inventoryWidget, &GridView<Resource*>::cellClicked, [this, &inventoryWidget, &ladang, &inventory, &player, &dialog](Location slot) {
        cout << slot << endl;
        // Plant *plant;
        // try {
        //     plant = player->takeInventory<Plant>(slot);
        // } catch (NotTakableException &e) {
        //     MessageBox(&window, "Tanam", "Lokasi yang dipilih bukan berisi tanaman.").exec();
        //     return;
        // }

        // MessageBox(&window, "Tanam", "Kamu memilih " + plant->getName() + " dari penyimpanan.").exec();

        // CetakLadang printer(state);
        // printer.printGrid(ladang);

        // dialog.close();
    });

    // // print label and grid penyimpanan
    // int total_length = petani->getInventory().getCol()*6 + 1;
    // string message = " Penyimpanan ";
    // string pad = string((total_length - message.length()) / 2 - 1, '=');
    // cout << "   " <<  pad << '[' << message << ']' << pad << endl;

    // GridDrawerCLI<Resource*> drawer = GridDrawerCLI<Resource*>(inventory);
    // drawer.draw();

    // cout << "\nSlot: ";
    // Location slot;
    // cin >> slot;

    // // Ambil tanaman dari penyimpanan
    // Plant *plant;
    // try {
    //     plant = player->takeInventory<Plant>(slot);
    // } catch (NotTakableException &e) {
    //     cout << "Lokasi yang dipilih bukan berisi tanaman.\n";
    //     cout << "Perintah tidak dilanjutkan.\n";
    //     return;
    // }

    // // Sukses mengambil tanaman dari penyimpanan
    // cout << "\nKamu memilih " << plant->getName() << " dari penyimpanan.\n\n";

    // // print label and grid ladang
    // CetakLadang printer(state);
    // printer.printGrid(ladang);


    // // Pilih lokasi tanah di ladang
    // cout << "\nPetak tanah: ";
    // Location loc; cin >> loc;


    // // Tanam tanaman ke ladang
    // try {
    //     ladang.setElement(loc, plant);
    // } catch (logic_error &e) {
    //     cout << "Petak tanah yang dipilih sudah terisi.\n";
    //     cout << "Perintah gagal dieksekusi.\n";
    //     return;
    // }

    // // Berhasil menanam tanaman
    // inventory.pop(slot);
    // cout << "Cangkul, cangkul, cangkul yang dalam~!\n";
    // cout << "Kamu telah menanam " << plant->getName() << " di petak tanah " << loc << ".\n\n";
    dialog.exec();
}
void Tanam::execute(Peternak *peternak) {
    MessageBox(&window, "Tanam", "Anda tidak dapat menanam tanaman!").exec();
}
void Tanam::execute(Walikota *walikota) {
    MessageBox(&window, "Tanam", "Anda tidak dapat menanam tanaman!").exec();
}
