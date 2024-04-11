#include "tubesoop1/gui/components/mainwindow.h"
#include "tubesoop1/gui/command/help.h"

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
    int margin = 5; int spacing = 10;
    tabPerintahLayout.addLayout(&vPendudukLayout, 0, 0);     vPendudukLayout.setContentsMargins(margin, margin, margin, margin); vPendudukLayout.setSpacing(spacing);
    tabPerintahLayout.addLayout(&vWalikotaLayout, 0, 1);     vWalikotaLayout.setContentsMargins(margin, margin, margin, margin); vWalikotaLayout.setSpacing(spacing);
    tabPerintahLayout.addLayout(&vPlayerLayout, 1, 0, 1, 3); vPlayerLayout.setContentsMargins(margin, margin, margin, margin);   vPlayerLayout.setSpacing(spacing);

    
    vPendudukLayout.addWidget(&tanamButton);
    
    vWalikotaLayout.addWidget(&pungutPajakButton);
    vWalikotaLayout.addWidget(&bangunButton);
    vWalikotaLayout.addWidget(&tambahPemainButton);
    vWalikotaLayout.addStretch();
    
    vPendudukLayout.addWidget(&ternakButton);
    vPendudukLayout.addWidget(&kasihMakanButton);
    vPendudukLayout.addWidget(&panenButton);
    vPendudukLayout.addWidget(&panenButton);
    vPendudukLayout.addStretch();

    vPlayerLayout.addWidget(&makanButton);
    vPlayerLayout.addWidget(&beliButton);
    vPlayerLayout.addWidget(&jualButton);
    vPlayerLayout.addWidget(&simpanButton);
    vPlayerLayout.addStretch();

    // footer
    footerLayout.addWidget(&helpButton);
    footerLayout.addStretch();
    footerLayout.addStretch();
    footerLayout.addStretch();
    footerLayout.addWidget(&nextButton);


    nextButton.connect(&nextButton, &QPushButton::pressed, [this](){
        state.nextTurn();
        statusBar.setPlayer(state.getCurrentPlayer());
        statusBar.refresh();
    });
    helpButton.connect(&helpButton, &QPushButton::pressed, [this](){
        Command* help = new Help(*this); 
        help->execute(state.getCurrentPlayer());
        // delete help;
    });
    
    cetakLadangButton.connect(&cetakLadangButton, &QPushButton::pressed, [](){});
    cetakPeternakanButton.connect(&cetakPeternakanButton, &QPushButton::pressed, [](){});
    cetakPenyimpananButton.connect(&cetakPenyimpananButton, &QPushButton::pressed, [](){});
    jualButton.connect(&jualButton, &QPushButton::pressed, [](){});
    makanButton.connect(&makanButton, &QPushButton::pressed, [](){});
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