#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

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

    QPushButton button("Press", &window);
    button.setGeometry(10, 10, 100, 30);
    button.show();
    button.setStyleSheet(
        "QPushButton { \
            background-color: rgb(124, 58, 237); \
            color: white; \
            border-radius: 15px; \
            font-size: 15px; \
            font-weight: bold; \
            padding: 10px 20px; \
        } \
        QPushButton:hover { \
            background-color: rgb(139, 92, 246); \
            color: white; \
        } \
        QPushButton:pressed { \
            background-color: rgb(91, 33, 182); \
        }"
    );
    window.setMenuWidget(&button);

    int counter = 0;
    button.connect(&button, &QPushButton::clicked, [&](){
        counter++;
        textEdit.setText("Button Pressed " + QString::number(counter) + " times");
    });

    return app.exec();
}
