#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/state/state.h"
#include "tubesoop1/resource/resourcefactory.h"

using namespace std;

class Dialog : public QDialog {
private:
    bool closable = true;
public:
    Dialog(QWidget* window);
    void moveCenter();

    
    void setClosable(bool closable);
    void closeEvent(QCloseEvent *event);
};


#endif