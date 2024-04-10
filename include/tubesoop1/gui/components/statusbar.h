#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QMainWindow>
#include <QVBoxLayout>
#include "tubesoop1/gui/components/nicebutton.h"
using namespace std;

class MainWindow : public QMainWindow {
private:
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
    MainWindow();
};


#endif