#include <iostream>
#include <tubesoop1/state/state.h>

#include <QApplication>
#include <QSize>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QWidget>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDialog>
#include <QFont>
#include <QFontDatabase>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QPoint>

#include <tubesoop1/gui/components/nicebutton.h>
#include <tubesoop1/gui/components/mainwindow.h>
#include <tubesoop1/gui/components/initdialog.h>
#include <tubesoop1/gui/game.h>
#include <tubesoop1/gui/components/application.h>
using namespace std;

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    int fontId = QFontDatabase::addApplicationFont("assets/font/Outfit-SemiBold.ttf");
    if(fontId != -1){
        QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont customFont(fontName);
        QApplication::setFont(customFont);
    }
    

    ResourceFactory factory("config");
    State state;

    MainWindow window(state);
    window.show();
    app.setMainWindow(&window);

    InitDialog initDialog(&window, state, factory);
    initDialog.setClosable(false);
    initDialog.moveCenter();
    initDialog.exec();

    window.initializeMenu();

    Game game(state, window);
    
    return app.exec();
}
