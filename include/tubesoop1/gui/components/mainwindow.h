#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QMainWindow>
#include <QVBoxLayout>
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/gui/components/statusbar.h"
#include "tubesoop1/state/state.h"
using namespace std;

class MainWindow : public QMainWindow {
private:
    StatusBar statusBar;

    QVBoxLayout vLayout;
    QVBoxLayout headerLayout;
    QVBoxLayout bodyLayout;
    QVBoxLayout footerLayout;

    QWidget centralWidget;
    QWidget headerWidget;
    QWidget bodyWidget;
    QWidget footerWidget;

    NiceButton cetakLadangButton;
    NiceButton cetakPeternakanButton;
    NiceButton cetakPenyimpananButton;
    NiceButton helpButton;
    NiceButton jualButton;
    NiceButton makanButton;
    NiceButton nextButton;
    NiceButton panenButton;
    NiceButton pungutPajakButton;
    NiceButton simpanButton;
    NiceButton tambahPemainButton;
    NiceButton ternakButton;
public:
    MainWindow(State &state);
};


#endif