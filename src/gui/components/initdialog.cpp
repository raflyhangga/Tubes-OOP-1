#include "tubesoop1/gui/components/initdialog.h"
#include "tubesoop1/gui/components/messagebox.h"
#include "tubesoop1/resource/resourcefactory_exception.h"
#include <QMessageBox>
#include <QRect>
#include <QGuiApplication>

InitDialog::InitDialog(QMainWindow* window, State &state, ResourceFactory &factory) : Dialog(window), loadFileStateButton("Load File State"), loadNewStateButton("Load New State"), label(QString::fromStdString("Apakah anda ingin memuat state baru/lama ?")){
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    setWindowModality(Qt::ApplicationModal); 

    setWindowTitle(QString::fromStdString("Load State"));
    setLayout(&vLayout);

    int margin = 10; setContentsMargins(margin, margin, margin, margin);

    vLayout.addWidget(&label);
    vLayout.addLayout(&hLayout);
    hLayout.addWidget(&loadFileStateButton);
    hLayout.addWidget(&loadNewStateButton);

    loadFileStateButton.connect(&loadFileStateButton, &QPushButton::clicked, [this, &state, &factory](){
        QString fileName = QFileDialog::getOpenFileName(this, QString::fromStdString("Open Directory"), "", QString::fromStdString("Text Files (*.txt)"));
        if(fileName != ""){
            try{
                state.load(fileName.toStdString(), factory);
                accept();
                MessageBox(this, "Success", "State baru berhasil dimuat!").exec();
            } catch (FileNotFoundException &e){
                MessageBox(this, "Failed", e.what()).exec();
            } catch (exception &e){
                MessageBox(this, "Failed", "Not a valid file!").exec();
            }
        }
    });

    loadNewStateButton.connect(&loadNewStateButton, &QPushButton::clicked, [this, &state, &factory](){
        try{
            state.loadNew(factory);
            accept();
            MessageBox(this, "Success", "State baru berhasil dimuat!").exec();
        } catch (exception &e){
            MessageBox(this, "Success", "State baru berhasil dimuat!").exec();
        }
    });
}

void InitDialog::setClosable(bool closable){
    this->closable = closable;
}
void InitDialog::closeEvent(QCloseEvent *event) {
    if(!closable) event->ignore();
}
