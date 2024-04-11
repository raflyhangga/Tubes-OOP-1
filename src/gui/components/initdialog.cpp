#include "tubesoop1/gui/components/initdialog.h"
#include "tubesoop1/resource/resourcefactory_exception.h"
#include <QMessageBox>

InitDialog::InitDialog(QMainWindow* window, State &state, ResourceFactory &factory) : QDialog(window), loadFileStateButton("Load File State"), loadNewStateButton("Load New State"), label(QString::fromStdString("Apakah anda ingin memuat state baru/lama ?")){
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    setWindowModality(Qt::ApplicationModal); 

    setWindowTitle(QString::fromStdString("Load State"));
    setLayout(&vLayout);

    int margin = 10; setContentsMargins(margin, margin, margin, margin);

    vLayout.addWidget(&label);
    vLayout.addLayout(&hLayout);
    hLayout.addWidget(&loadFileStateButton);
    hLayout.addWidget(&loadNewStateButton);

    loadFileStateButton.connect(&loadFileStateButton, &QPushButton::pressed, [this, &state, &factory](){
        QString fileName = QFileDialog::getOpenFileName(this, QString::fromStdString("Open Directory"), "", QString::fromStdString("Text Files (*.txt)"));
        if(fileName != ""){
            try{
                state.load(fileName.toStdString(), factory);
                accept();
                QMessageBox messageBox(this); messageBox.setModal(true);
                messageBox.setText(QString::fromStdString("State baru berhasil dimuat!"));
                messageBox.exec();
            } catch (FileNotFoundException &e){
                QMessageBox messageBox(this); messageBox.setModal(true);
                messageBox.setText(QString::fromStdString(e.what()));
            } catch (exception &e){
                QMessageBox messageBox(this); messageBox.setModal(true);
                messageBox.setText(QString::fromStdString("Not a valid file!"));
                messageBox.exec();
            }
        }
    });

    loadNewStateButton.connect(&loadNewStateButton, &QPushButton::pressed, [this, &state, &factory](){
        try{
            state.loadNew(factory);
            accept();
            QMessageBox messageBox(this); messageBox.setModal(true);
            messageBox.setText(QString::fromStdString("State baru berhasil dimuat!"));
            messageBox.exec();
        } catch (exception &e){
            QMessageBox messageBox(this); messageBox.setModal(true);
            messageBox.setText(QString::fromStdString(e.what()));
            messageBox.exec();
        }
    });

}

void InitDialog::setClosable(bool closable){
    this->closable = closable;
}
void InitDialog::closeEvent(QCloseEvent *event) {
    if(!closable) event->ignore();
}