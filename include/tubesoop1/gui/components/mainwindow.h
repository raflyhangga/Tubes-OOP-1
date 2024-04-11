#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QGridLayout>
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/gui/components/statusbar.h"
#include "tubesoop1/gui/components/gridview.hpp"
#include "tubesoop1/state/state.h"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/plant/plant.h"
using namespace std;

class MainWindow : public QMainWindow {
private:
    State &state;
    StatusBar statusBar;

    // CetakPenyimpanan, CetakPeternakan, CetakLadang
    QTabWidget tabWidget;
    QWidget tabPerintah;    QGridLayout tabPerintahLayout;
    GridView<Resource*> tabPenyimpanan;
    GridView<Animal*> tabPeternakan; 
    GridView<Plant*> tabLadang;     

    QVBoxLayout vPendudukLayout;
    QVBoxLayout vWalikotaLayout;
    QVBoxLayout vPlayerLayout;

    QVBoxLayout vLayout;
    QVBoxLayout headerLayout;
    QVBoxLayout bodyLayout;
    QHBoxLayout footerLayout;

    QWidget centralWidget;
    QWidget headerWidget;
    QWidget bodyWidget;
    QWidget footerWidget;


public:
    MainWindow(State &state);
    void initializeMenu();
    
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
    // NiceButton statusButton;
    NiceButton helpButton;
    // NiceButton exitButton;

    GridView<Resource*> &getTabPenyimpanan();
    GridView<Animal*> &getTabPeternakan(); 
    GridView<Plant*> &getTabLadang();   
    StatusBar &getStatusBar();   
};


#endif