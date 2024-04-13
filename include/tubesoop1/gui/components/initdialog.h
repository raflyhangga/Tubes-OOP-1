#ifndef INIT_DIALOG_H
#define INIT_DIALOG_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QCloseEvent>
#include <QMouseEvent>
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/state/state.h"
#include "tubesoop1/resource/resourcefactory.h"

using namespace std;

class InitDialog : public QDialog {
private:
    QWidget stateOptionWidget;
    NiceButton loadFileStateButton;
    NiceButton loadNewStateButton;
    QFileDialog fileDialog;
    QVBoxLayout vLayout;
    QHBoxLayout hLayout;
    QLabel label;
    bool closable;
public:
    InitDialog(QMainWindow* window, State &state, ResourceFactory &factory);

    void setClosable(bool closable);
    void closeEvent(QCloseEvent *event);
};


#endif