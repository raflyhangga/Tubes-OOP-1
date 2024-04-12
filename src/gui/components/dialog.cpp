#include "tubesoop1/gui/components/dialog.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent){
    setWindowModality(Qt::ApplicationModal); 
    setModal(true);
};