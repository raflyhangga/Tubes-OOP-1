#include <tubesoop1/gui/command/tambahpemain.h>
#include <tubesoop1/gui/components/messagebox.h>
#include <tubesoop1/gui/components/inputdialog.h>
#include <QString>
#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

TambahPemain::TambahPemain(State &state, MainWindow& window) : Command(state, window) {}

void TambahPemain::execute(Petani *petani) {
    MessageBox(&window, "Tambah Pemain", "Anda tidak dapat menambah pemain!").exec();
}
void TambahPemain::execute(Peternak *peternak) {
    MessageBox(&window, "Tambah Pemain", "Anda tidak dapat menambah pemain!").exec();
}
void TambahPemain::execute(Walikota *walikota) {
    if(walikota->getMoney() < 50){
        MessageBox(&window, "Tambah Pemain", "Uang tidak cukup!").exec();
        return;
    }
    // Create the dialog
    QDialog dialog;
    dialog.setStyleSheet(R"(
        QDialog {
            background-color: rgb(2, 6, 23);
            color: white;
            font-size: 17px;
            font-weight: bold;
        }
        QDialog QLabel {
            color: white;
        }
        QDialog QComboBox {
            color: white;
            background-color: rgb(17, 24, 39);
            border-radius: 15px;
        }
        QDialog QComboBox::item {
            background-color: rgb(17, 24, 39);
            color: white;
        }
        QDialog QComboBox::item:selected {
            color: white;
            background-color: rgb(51, 65, 85);
        }
        QDialog QLineEdit {
            color: white;
            background-color: rgb(17, 24, 39);
            border-radius: 15px;
            padding: 10px 20px;
        }
        QDialog QPushButton {
            background-color: rgb(124, 58, 237);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QDialog QPushButton:hover {
            background-color: rgb(139, 92, 246);
            color: white;
        }
        QDialog QPushButton:pressed {
            background-color: rgb(91, 33, 182);
        }
    )");
    
    dialog.setWindowTitle("Tambah Pemain");

    QLabel label("Role:");
    QComboBox comboBox;
    comboBox.addItem("Peternak");
    comboBox.addItem("Petani");
    QLineEdit lineEdit;
    QLabel textLabel("Nama:");
    NiceButton okButton("OK");
    NiceButton cancelButton("Cancel");

    QVBoxLayout mainLayout(&dialog);
    QHBoxLayout buttonLayout;
    buttonLayout.addWidget(&okButton);
    buttonLayout.addWidget(&cancelButton);
    mainLayout.addWidget(&label);
    mainLayout.addWidget(&comboBox);
    mainLayout.addWidget(&textLabel);
    mainLayout.addWidget(&lineEdit);
    mainLayout.addLayout(&buttonLayout);

    cancelButton.connect(&cancelButton, &QPushButton::clicked, [&](){
        dialog.reject();
    });
    okButton.connect(&okButton, &QPushButton::clicked, [&](){
        string type = comboBox.currentText().toStdString();
        string name = lineEdit.text().toStdString();

        if(state.isPlayerExist(name)){
            MessageBox(&window, "Tambah Pemain", "Nama pemain sudah pernah ada!").exec();
            return;
        }
        
        state.addPlayer(type, name);
        if(name < walikota->getUsername()){
            state.nextTurn();
        }
        walikota->addMoney(-50);
        
        dialog.accept();
        MessageBox(&window, "Tambah Pemain", "Pemain baru ditambahkan!\n Selamat datang " + name + " di kota ini!").exec();
        
    });

    dialog.exec();


}

