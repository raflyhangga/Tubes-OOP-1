#include "tubesoop1/gui/components/mainwindow.h"

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
    setMinimumSize(QSize(1280, 720));
}

void MainWindow::initializeMenu(){
    statusBar.setPlayer(state.getCurrentPlayer());


    // Whole
    setCentralWidget(&centralWidget);
    centralWidget.setLayout(&vLayout);

    // Divide 3 section: header, body, footer
    vLayout.addWidget(&headerWidget); headerWidget.setLayout(&headerLayout);
    vLayout.addWidget(&bodyWidget);   bodyWidget.setLayout(&bodyLayout);
    vLayout.addWidget(&footerWidget); footerWidget.setLayout(&footerLayout);

    // header
    headerLayout.addWidget(&statusBar);

    // body
    bodyLayout.addWidget(&tabWidget); 
    tabWidget.addTab(&tabPerintah, "Perintah");
    tabWidget.addTab(&tabPenyimpanan, "Penyimpanan");
    tabWidget.addTab(&tabPeternakan, "Peternakan");
    tabWidget.addTab(&tabLadang, "Ladang");

    tabPerintah.setLayout(&tabPerintahLayout);
    tabPerintahLayout.addLayout(&vPetaniLayout, 0, 1);
    tabPerintahLayout.addLayout(&vPeternakLayout, 0, 2);
    tabPerintahLayout.addLayout(&vWalikotaLayout, 0, 3);
    tabPerintahLayout.addLayout(&vPlayerLayout, 1, 0, 1, 4);

    
    vPetaniLayout.addWidget(&tanamButton);
    vPetaniLayout.addWidget(&panenButton);
    vWalikotaLayout.addWidget(&pungutPajakButton);
    vWalikotaLayout.addWidget(&bangunButton);
    vWalikotaLayout.addWidget(&tambahPemainButton);
    vPeternakLayout.addWidget(&ternakButton);
    vPeternakLayout.addWidget(&kasihMakanButton);
    vPlayerLayout.addWidget(&makanButton);
    vPlayerLayout.addWidget(&beliButton);
    vPlayerLayout.addWidget(&jualButton);
    vPlayerLayout.addWidget(&simpanButton);
    vPlayerLayout.addWidget(&helpButton);

    // tabPerintah.setLayout(&tabPerintahLayout);
    // // tabPerintahLayout.addWidget(&cetakPenyimpananButton);
    // tabPerintahLayout.addWidget(&pungutPajakButton);
    // // tabPerintahLayout.addWidget(&cetakLadangButton);
    // // tabPerintahLayout.addWidget(&cetakPeternakanButton);
    // tabPerintahLayout.addWidget(&tanamButton);
    // tabPerintahLayout.addWidget(&ternakButton);
    // tabPerintahLayout.addWidget(&bangunButton);
    // tabPerintahLayout.addWidget(&makanButton);
    // tabPerintahLayout.addWidget(&kasihMakanButton);
    // tabPerintahLayout.addWidget(&beliButton);
    // tabPerintahLayout.addWidget(&jualButton);
    // tabPerintahLayout.addWidget(&panenButton);
    // tabPerintahLayout.addWidget(&simpanButton);
    // tabPerintahLayout.addWidget(&tambahPemainButton);
    // tabPerintahLayout.addWidget(&helpButton);

    // footer
    footerLayout.addStretch();
    footerLayout.addStretch();
    footerLayout.addStretch();
    footerLayout.addWidget(&nextButton);


    cetakLadangButton.connect(&cetakLadangButton, &QPushButton::pressed, [](){});
    cetakPeternakanButton.connect(&cetakPeternakanButton, &QPushButton::pressed, [](){});
    cetakPenyimpananButton.connect(&cetakPenyimpananButton, &QPushButton::pressed, [](){});
    helpButton.connect(&helpButton, &QPushButton::pressed, [](){});
    jualButton.connect(&jualButton, &QPushButton::pressed, [](){});
    makanButton.connect(&makanButton, &QPushButton::pressed, [](){});
    nextButton.connect(&nextButton, &QPushButton::pressed, [this](){
        state.nextTurn();
        statusBar.setPlayer(state.getCurrentPlayer());
        statusBar.refresh();
    });
    panenButton.connect(&panenButton, &QPushButton::pressed, [](){});
    pungutPajakButton.connect(&pungutPajakButton, &QPushButton::pressed, [](){});
    simpanButton.connect(&simpanButton, &QPushButton::pressed, [](){});
    tambahPemainButton.connect(&tambahPemainButton, &QPushButton::pressed, [](){});
    ternakButton.connect(&ternakButton, &QPushButton::pressed, [](){});
}

void MainWindow::addPetaniButton(QPushButton& button){
    tabPerintahLayout.addWidget(&button, 0, 0);
}
void MainWindow::addPeternakButton(QPushButton& button){
    tabPerintahLayout.addWidget(&button, 0, 1);
}
void MainWindow::addWalikotaButton(QPushButton& button){
    tabPerintahLayout.addWidget(&button, 0, 2);
}
void MainWindow::addPlayerButton(QPushButton& button){
    tabPerintahLayout.addWidget(&button, 1, 0, 1, 3);
}