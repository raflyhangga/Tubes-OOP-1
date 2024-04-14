#include "tubesoop1/gui/components/dialog.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QPoint>

Dialog::Dialog(QWidget* parent) : QDialog(parent){
    setWindowModality(Qt::ApplicationModal); 
    setModal(true);
};

void Dialog::moveCenter() {
    QDesktopWidget *desktop = QApplication::desktop();
    int screenIndex = desktop->screenNumber(this);
    QRect screenGeometry = desktop->screenGeometry(screenIndex);
    QPoint centerPoint = screenGeometry.center();
    move(centerPoint.x() - width() / 2, centerPoint.y() - height() / 2);
}