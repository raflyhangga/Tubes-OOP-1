#include "tubesoop1/gui/command/ternak.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include "tubesoop1/player/player_partial.hpp"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include <tubesoop1/resourcevisitorpattern/taker.hpp>
#include "tubesoop1/gui/command/command_exception.h"
#include "tubesoop1/gui/components/dialog.h"
#include "tubesoop1/gui/components/messagebox.h"

Ternak::Ternak(State &state, MainWindow &window) : Command(state, window) {}

void Ternak::execute(Peternak *peternak) {
    vector<Animal*> list = peternak->takeAllFromInventory<Animal>();
    if(list.size()==0){
        MessageBox(&window, "Ternak", "Tidak ada hewan di penyimpanan!").exec(); return;
    }
    if(peternak->getPeternakan().isFull()){
        MessageBox(&window, "Ternak", "Peternakan penuh!").exec(); return;
    }

    Dialog dialogInventory(&window); dialogInventory.setWindowTitle("Ternak");

    QVBoxLayout vLayout;
    dialogInventory.setLayout(&vLayout);
    QLabel label("Pilih hewan dari penyimpanan");
    QLabel gridTitle("Penyimpanan"); gridTitle.setAlignment(Qt::AlignCenter);
    vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

    GridView<Resource*> inventoryButtonGrid;
    inventoryButtonGrid.setMinimumSize(QSize(960, 540));
    inventoryButtonGrid.setGrid(&peternak->getInventory());
    inventoryButtonGrid.setEnabled(true);
    vLayout.addWidget(&inventoryButtonGrid);

    inventoryButtonGrid.connect(&inventoryButtonGrid, &GridView<Resource*>::cellClicked, [this, &peternak, &dialogInventory](Location slot) {
        // // Ambil tanaman dari penyimpanan
        Animal *animal;
        try {
            animal = peternak->takeInventory<Animal>(slot);
        } catch (NotTakableException &e) {
            MessageBox(&window, "Ternak", "HEY HEY HEY APA ITU YG MAU ANDA MASUKKAN KE KANDANG!\nMasukkan slot lagi brok.").exec();
            return;
        } catch (logic_error &e) {
            MessageBox(&window, "Ternak", "Lokasi yang dipilih kosong.\nPerintah tidak dilanjutkan.").exec(); return;
        }
        // // Sukses mengambil tanaman dari penyimpanan
        MessageBox(&window, "Ternak", "Kamu memilih " + formatName(animal->getName()) + " dari penyimpanan.\n\n").exec();
        dialogInventory.close();

        // // print label and grid ladang
        Dialog dialogPeternakan(&window); dialogPeternakan.setWindowTitle("Ternak");

        QVBoxLayout vLayout;
        dialogPeternakan.setLayout(&vLayout);
        QLabel label("Pilih lokasi tanah di peternakan:");
        QLabel gridTitle("Peternakan"); gridTitle.setAlignment(Qt::AlignCenter);
        vLayout.addWidget(&label); vLayout.addWidget(&gridTitle);

        GridView<Animal*> peternakanButtonGrid;
        peternakanButtonGrid.setMinimumSize(QSize(960, 540));
        peternakanButtonGrid.setGrid(&peternak->getPeternakan());
        peternakanButtonGrid.setEnabled(true);
        vLayout.addWidget(&peternakanButtonGrid);

        peternakanButtonGrid.connect(&peternakanButtonGrid, &GridView<Animal*>::cellClicked, [this, &peternak, &animal, &slot, &dialogPeternakan, &peternakanButtonGrid](Location loc) {

            // // Tanam tanaman ke ladang
            try {
                peternak->getPeternakan().setElement(loc, animal);
            } catch (logic_error &e) {
                MessageBox(&window, "Ternak", "Petak tanah yang dipilih sudah terisi.\nPerintah gagal dieksekusi.").exec();
                return;
            }

            // // Berhasil menanam tanaman
            peternak->getInventory().pop(slot);
            peternakanButtonGrid.refresh();
            MessageBox(&window, "Ternak", "Dengan hati-hati, kamu meletakkan seekor " + formatName(animal->getName()) + " di petak tanah " + loc.toStdString() + ".\n" + formatName(animal->getName()) + " telah menjadi peliharaanmu sekarang!").exec();

            dialogPeternakan.close();
        });

        dialogPeternakan.exec();
    });

    dialogInventory.exec();
    
}

void Ternak::execute(Petani *petani) {
    MessageBox(&window, "Ternak", "Anda tidak dapat melakukan ternak!").exec();
}

void Ternak::execute(Walikota *walikota) {
    MessageBox(&window, "Ternak", "Anda tidak dapat melakukan ternak!").exec();
}