#ifndef INPUT_DIALOG_H
#define INPUT_DIALOG_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QInputDialog>
#include <QMainWindow>
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/state/state.h"
#include "tubesoop1/resource/resourcefactory.h"

using namespace std;

class InputDialog : public QInputDialog {
public:
    InputDialog(QMainWindow* window, string title, string label);
};


#endif