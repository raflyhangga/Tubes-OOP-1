#include "tubesoop1/gui/components/dialog.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QPoint>

Dialog::Dialog(QWidget* parent) : QDialog(parent){
    setWindowModality(Qt::ApplicationModal); 
    setModal(true);
    setStyleSheet(R"(
        QDialog {
            background-color: rgb(2, 6, 23);
            color: white;
            font-size: 17px;
            font-weight: bold;
        }
        QDialog QLabel {
            color: white;
        }
        QDialog QComboBox {
            color: white;
            background-color: rgb(17, 24, 39);
            border-radius: 15px;
        }
        QDialog QComboBox::item {
            background-color: rgb(17, 24, 39);
            color: white;
        }
        QDialog QComboBox::item:selected {
            color: white;
            background-color: rgb(51, 65, 85);
        }
        QDialog QLineEdit {
            color: white;
            background-color: rgb(17, 24, 39);
            border-radius: 15px;
            padding: 10px 20px;
        }
        QDialog QPushButton {
            background-color: rgb(124, 58, 237);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QDialog QPushButton:hover {
            background-color: rgb(139, 92, 246);
            color: white;
        }
        QDialog QPushButton:pressed {
            background-color: rgb(91, 33, 182);
        }
    )");
};

void Dialog::moveCenter() {
    QDesktopWidget *desktop = QApplication::desktop();
    int screenIndex = desktop->screenNumber(this);
    QRect screenGeometry = desktop->screenGeometry(screenIndex);
    QPoint centerPoint = screenGeometry.center();
    move(centerPoint.x() - width() / 2, centerPoint.y() - height() / 2);
}