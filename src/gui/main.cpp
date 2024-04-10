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

#include <tubesoop1/gui/components/nicebutton.h>
#include <tubesoop1/gui/components/mainwindow.h>
#include <tubesoop1/gui/components/initdialog.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ResourceFactory factory("config");
    State state;

    MainWindow window(state);
    window.show();

    InitDialog initDialog(&window, state, factory);
    initDialog.exec();
    
    return app.exec();
}
