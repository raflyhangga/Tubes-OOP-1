#include "tubesoop1/gui/components/messagebox.h"
#include <QApplication>
#include <QRect>
#include <QDesktopWidget>

MessageBox::MessageBox(QWidget* window, string title, string message) : QMessageBox(window) {
    setModal(true);
    QMessageBox::setText(QString::fromStdString(message));
    QMessageBox::setWindowTitle(QString::fromStdString(title));
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setContentsMargins(10, 10, 10, 10);
}

void MessageBox::setText(string message) {
    QMessageBox::setText(QString::fromStdString(message));
}
