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
    vector<Plant*> list = petani->takeAllFromInventory<Plant>();
    if(list.size()==0){
        MessageBox(&window, "Tanam", "Tidak ada tanaman di penyimpanan!").exec(); return;
    }
    if(petani->getLadang().isFull()){
        MessageBox(&window, "Tanam", "Ladang penuh!").exec(); return;
    }

    Dialog dialogInventory(&window);

    QVBoxLayout vLayout;
    dialogInventory.setLayout(&vLayout); dialogInventory.setWindowTitle("Tanam");
    QLabel label("Pilih tanaman dari penyimpanan");
    QLabel gridTitle("Penyimpanan"); gridTitle.setAlignment(Qt::AlignCenter);
    vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

    GridView<Resource*> inventoryButtonGrid;
    inventoryButtonGrid.setMinimumSize(QSize(960, 540));
    inventoryButtonGrid.setGrid(&petani->getInventory());
    inventoryButtonGrid.setEnabled(true);
    vLayout.addWidget(&inventoryButtonGrid);

    inventoryButtonGrid.connect(&inventoryButtonGrid, &GridView<Resource*>::cellClicked, [this, &petani, &dialogInventory](Location slot) {
        // // Ambil tanaman dari penyimpanan
        Plant *plant;
        try {
            plant = petani->takeInventory<Plant>(slot);
        } catch (NotTakableException &e) {
            MessageBox(&dialogInventory, "Tanam", "Lokasi yang dipilih bukan berisi tanaman.\nPerintah tidak dilanjutkan.").exec(); return;
        } catch (logic_error &e) {
            MessageBox(&dialogInventory, "Tanam", "Lokasi yang dipilih kosong.\nPerintah tidak dilanjutkan.").exec(); return;
        }
        // // Sukses mengambil tanaman dari penyimpanan
        MessageBox(&dialogInventory, "Tanam", "Kamu memilih " + formatName(plant->getName()) + " dari penyimpanan.\n\n").exec();
        dialogInventory.close();

        // // print label and grid ladang
        Dialog dialogLadang(&window); dialogLadang.setWindowTitle("Tanam");

        QVBoxLayout vLayout;
        dialogLadang.setLayout(&vLayout);
        QLabel label("Pilih lokasi tanah di ladang:");
        QLabel gridTitle("Ladang"); gridTitle.setAlignment(Qt::AlignCenter);
        vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

        GridView<Plant*> ladangButtonGrid;
        ladangButtonGrid.setMinimumSize(QSize(960, 540));
        ladangButtonGrid.setGrid(&petani->getLadang());
        ladangButtonGrid.setEnabled(true);
        vLayout.addWidget(&ladangButtonGrid);

        ladangButtonGrid.connect(&ladangButtonGrid, &GridView<Plant*>::cellClicked, [this, &petani, &plant, &slot, &dialogLadang, &ladangButtonGrid](Location loc) {

            // // Tanam tanaman ke ladang
            try {
                petani->getLadang().setElement(loc, plant);
            } catch (logic_error &e) {
                MessageBox(&dialogLadang, "Tanam", "Petak tanah yang dipilih sudah terisi.\nPerintah gagal dieksekusi.").exec(); return;
            }

            // // Berhasil menanam tanaman
            petani->getInventory().pop(slot);
            ladangButtonGrid.refresh();
            MessageBox(&dialogLadang, "Tanam", "Cangkul, cangkul, cangkul yang dalam~!\nKamu telah menanam " + formatName(plant->getName()) + " di petak tanah " + loc.toStdString() + ".").exec();

            dialogLadang.close();
        });

        dialogLadang.exec();
    });

    dialogInventory.exec();
}
void Tanam::execute(Peternak *peternak) {
    MessageBox(&window, "Tanam", "Anda tidak dapat menanam tanaman!").exec();
}
void Tanam::execute(Walikota *walikota) {
    MessageBox(&window, "Tanam", "Anda tidak dapat menanam tanaman!").exec();
}
