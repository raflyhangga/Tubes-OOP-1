#include "tubesoop1/gui/components/mainwindow.h"

MainWindow::MainWindow() : 
    cetakLadangButton("Cetak Ladang"),
    cetakPeternakanButton("Cetak Peternakan"),
    cetakPenyimpananButton("Cetak Penyimpanan"),
    helpButton("Help"),
    jualButton("Jual"),
    makanButton("Makan"),
    nextButton("Next"),
    panenButton("Panen"),
    pungutPajakButton("Pungut Pajak"),
    simpanButton("Simpan"),
    tambahPemainButton("Tambah Pemain"),
    ternakButton("Ternak")
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

    // Whole
    setCentralWidget(&centralWidget);
    centralWidget.setLayout(&vLayout);

    // Divide 3 section: header, body, footer
    vLayout.addWidget(&headerWidget); headerWidget.setLayout(&headerLayout);
    vLayout.addWidget(&bodyWidget);   bodyWidget.setLayout(&bodyLayout);
    vLayout.addWidget(&footerWidget); footerWidget.setLayout(&footerLayout);

    headerLayout.addWidget(&cetakLadangButton);
    bodyLayout.addWidget(&cetakPeternakanButton);
    bodyLayout.addWidget(&cetakPenyimpananButton);
    bodyLayout.addWidget(&helpButton);
    bodyLayout.addWidget(&jualButton);
    bodyLayout.addWidget(&makanButton);
    bodyLayout.addWidget(&nextButton);
    bodyLayout.addWidget(&panenButton);
    bodyLayout.addWidget(&pungutPajakButton);
    bodyLayout.addWidget(&simpanButton);
    bodyLayout.addWidget(&tambahPemainButton);
    footerLayout.addWidget(&ternakButton);


    cetakLadangButton.connect(&cetakLadangButton, &QPushButton::pressed, [](){});
    cetakPeternakanButton.connect(&cetakPeternakanButton, &QPushButton::pressed, [](){});
    cetakPenyimpananButton.connect(&cetakPenyimpananButton, &QPushButton::pressed, [](){});
    helpButton.connect(&helpButton, &QPushButton::pressed, [](){});
    jualButton.connect(&jualButton, &QPushButton::pressed, [](){});
    makanButton.connect(&makanButton, &QPushButton::pressed, [](){});
    nextButton.connect(&nextButton, &QPushButton::pressed, [](){});
    panenButton.connect(&panenButton, &QPushButton::pressed, [](){});
    pungutPajakButton.connect(&pungutPajakButton, &QPushButton::pressed, [](){});
    simpanButton.connect(&simpanButton, &QPushButton::pressed, [](){});
    tambahPemainButton.connect(&tambahPemainButton, &QPushButton::pressed, [](){});
    ternakButton.connect(&ternakButton, &QPushButton::pressed, [](){});
}
