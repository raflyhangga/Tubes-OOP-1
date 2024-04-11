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
    State &state;
    StatusBar statusBar;

    QVBoxLayout vLayout;
    QVBoxLayout headerLayout;
    QVBoxLayout bodyLayout;
    QHBoxLayout footerLayout;

    QWidget centralWidget;
    QWidget headerWidget;
    QWidget bodyWidget;
    QWidget footerWidget;

    NiceButton nextButton;
    NiceButton cetakPenyimpananButton;
    NiceButton pungutPajakButton;
    NiceButton cetakLadangButton;
    NiceButton cetakPeternakanButton;
    NiceButton tanamButton;
    NiceButton ternakButton;
    NiceButton bangunButton;
    NiceButton makanButton;
    NiceButton kasihMakanButton;
    NiceButton beliButton;
    NiceButton jualButton;
    NiceButton panenButton;
    // NiceButton muatButton;
    NiceButton simpanButton;
    NiceButton tambahPemainButton;
    NiceButton statusButton;
    NiceButton helpButton;
    // NiceButton exitButton;
public:
    MainWindow(State &state);
    void initializeMenu();
};


#endif