#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include "tubesoop1/gui/components/nicebutton.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Tubes OOP 1");
    window.setStyleSheet(
        " \
            background-color: rgb(2, 6, 23); \
            color: white; \
            font-size: 17px; \
            font-weight: bold; \
        " \
    );
    window.setGeometry(100, 100, 400, 200);
    window.show();

    QTextEdit textEdit;
    textEdit.setText("Hello, World!");
    textEdit.setLineWrapMode(QTextEdit::NoWrap);
    textEdit.show();
    window.setCentralWidget(&textEdit);

    NiceButton button("Press");
    window.setMenuWidget(&button);

    int counter = 0;
    button.connect(&button, &QPushButton::clicked, [&](){
        counter++;
        textEdit.setText("Button Pressed " + QString::number(counter) + " times");
    });

    return app.exec();
}
