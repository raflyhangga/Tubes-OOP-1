#include <tubesoop1/gui/command/simpan.h>
#include <tubesoop1/state/state_exception.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <QFileDialog>
#include <QString>

Simpan::Simpan(State &state, MainWindow& window) : Command(state, window) {}

void Simpan::execute(Player *player) {
    QString fileName = QFileDialog::getSaveFileName(&window, QString::fromStdString("Save File"), "", QString::fromStdString("Text Files (*.txt)"));
    if(fileName != ""){
        try{
            state.save(fileName.toStdString());
            MessageBox(&window, "Success", "State berhasil disimpan!").exec();
        } catch (FolderNotFoundException &e){
            MessageBox(&window, "Failed", "Lokasi berkas tidak valid").exec();
        } catch (exception &e){
            MessageBox(&window, "Failed", e.what()).exec();
        }
    }
}


