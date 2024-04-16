#include "tubesoop1/gui/components/mainwindow.h"
#include "tubesoop1/gui/components/statusbar.h"
#include <tubesoop1/gui/command/command.h>
#include <tubesoop1/gui/command/help.h>
#include <tubesoop1/gui/command/next.h>

#include <QSizePolicy>

MainWindow::MainWindow(State &state) :
    state(state),
    nextButton("Next"),
    // cetakPenyimpananButton("CetakPenyimpanan"),
    pungutPajakButton("PungutPajak"),
    // cetakLadangButton("CetakLadang"),
    // cetakPeternakanButton("CetakPeternakan"),
    tanamButton("Tanam"),
    ternakButton("Ternak"),
    bangunButton("Bangun"),
    makanButton("Makan"),
    kasihMakanButton("KasihMakan"),
    beliButton("Beli"),
    jualButton("Jual"),
    panenButton("Panen"),
    // muatButton("Muat"),
    simpanButton("Simpan"),
    tambahPemainButton("TambahPemain"),
    // statusButton("Status"),
    helpButton("Help")
    // exitButton("Exit")
{
    setWindowTitle("Tubes OOP 1");
    setStyleSheet(
        " \
            background-color: rgb(2, 6, 23); \
            color: white; \
            font-size: 17px; \
            font-weight: bold; \
        " \
    );
    int margin = 10; setContentsMargins(margin, margin, margin, margin);
    setGeometry(100, 100, 400, 200);
    setMinimumSize(QSize(1280, 840));
}

void MainWindow::initializeMenu(){
    statusBar.setPlayer(state.getCurrentPlayer());


    // Whole
    setCentralWidget(&centralWidget);
    centralWidget.setLayout(&vLayout);

    // Divide 3 section: header, body, footer
    vLayout.addWidget(&headerWidget, 0); headerWidget.setLayout(&headerLayout);
    vLayout.addWidget(&bodyWidget, 1);   bodyWidget.setLayout(&bodyLayout);
    vLayout.addStretch();
    vLayout.addWidget(&footerWidget, 0); footerWidget.setLayout(&footerLayout);
    vLayout.setSpacing(0);

    // header
    headerLayout.addWidget(&statusBar, 0);
    headerWidget.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    headerWidget.setContentsMargins(0, 0, 0, 0);

    // body
    int m = 15;
    bodyLayout.addWidget(&tabWidget, 1); 
    tabWidget.addTab(&tabPerintah, "Perintah");
    tabWidget.addTab(&tabPenyimpanan, "Penyimpanan");   tabPenyimpanan.setLayout(&tabPenyimpananVLayout);    tabPenyimpananVLayout.addWidget(&gridPenyimpanan, 1);    tabPenyimpananVLayout.addWidget(&tabPenyimpananLabel, 0);     tabPenyimpananLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);      gridPenyimpanan.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    tabPenyimpanan.setContentsMargins(m,m,m,m);
    tabWidget.addTab(&tabPeternakan, "Peternakan");     tabPeternakan.setLayout(&tabPeternakanVLayout);      tabPeternakanVLayout.addWidget(&gridPeternakan, 1);      tabPeternakanVLayout.addWidget(&tabPeternakanLabel, 0);       tabPeternakanLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);       gridPeternakan.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    tabPeternakan.setContentsMargins(m,m,m,m);
    tabWidget.addTab(&tabLadang, "Ladang");             tabLadang.setLayout(&tabLadangVLayout);              tabLadangVLayout.addWidget(&gridLadang, 1);              tabLadangVLayout.addWidget(&tabLadangLabel, 0);               tabLadangLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);           gridLadang.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    tabLadang.setContentsMargins(m,m,m,m);

    tabWidget.setContentsMargins(0, 0, 0, 0);
    bodyLayout.setContentsMargins(0, 0, 0, 0);

    tabPerintah.setLayout(&tabPerintahLayout); tabPerintahLayout.setContentsMargins(0, 0, 0, 0);
    int margin = 5; int spacing = 10;
    tabPerintahLayout.addLayout(&vPendudukLayout, 0, 0);     vPendudukLayout.setContentsMargins(margin, margin, margin, margin); vPendudukLayout.setSpacing(spacing);
    tabPerintahLayout.addLayout(&vWalikotaLayout, 0, 1);     vWalikotaLayout.setContentsMargins(margin, margin, margin, margin); vWalikotaLayout.setSpacing(spacing);
    tabPerintahLayout.addLayout(&vPlayerLayout, 1, 0, 1, 2); vPlayerLayout.setContentsMargins(margin, margin, margin, margin);   vPlayerLayout.setSpacing(spacing);

    
    
    vWalikotaLayout.addWidget(&pungutPajakButton);      pungutPajakButton.setStyleNormalCheckable();
    vWalikotaLayout.addWidget(&bangunButton);           bangunButton.setStyleNormalCheckable();
    vWalikotaLayout.addWidget(&tambahPemainButton);     tambahPemainButton.setStyleNormalCheckable();
    vWalikotaLayout.addStretch();                       
    
    vPendudukLayout.addWidget(&tanamButton);            tanamButton.setStyleNormalCheckable();
    vPendudukLayout.addWidget(&ternakButton);           ternakButton.setStyleNormalCheckable();
    vPendudukLayout.addWidget(&kasihMakanButton);       kasihMakanButton.setStyleNormalCheckable();
    vPendudukLayout.addWidget(&panenButton);            panenButton.setStyleNormalCheckable();
    vPendudukLayout.addStretch();

    vPlayerLayout.addWidget(&makanButton);              makanButton.setStyleNormalCheckable();
    vPlayerLayout.addWidget(&beliButton);               beliButton.setStyleNormalCheckable();
    vPlayerLayout.addWidget(&jualButton);               jualButton.setStyleNormalCheckable();
    vPlayerLayout.addStretch();

    // footer
    footerLayout.addWidget(&helpButton, 0);                
    // footerLayout.addStretch();
    footerLayout.addWidget(&simpanButton, 0);
    // footerLayout.addStretch();
    footerLayout.addWidget(&nextButton, 0);
    
}

StatusBar& MainWindow::getStatusBar(){
    return statusBar;
}

GridView<Resource*>& MainWindow::getTabPenyimpanan(){
    return gridPenyimpanan;
}
GridView<Animal*>& MainWindow::getTabPeternakan(){
    return gridPeternakan;
} 
GridView<Plant*>& MainWindow::getTabLadang(){
    return gridLadang;
}

QLabel& MainWindow::getTabPenyimpananLabel(){
    return tabPenyimpananLabel;
}

QLabel& MainWindow::getTabPeternakanLabel(){
    return tabPeternakanLabel;
}

QLabel& MainWindow::getTabLadangLabel(){
    return tabLadangLabel;
}