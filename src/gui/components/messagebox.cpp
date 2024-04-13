#include "tubesoop1/gui/components/messagebox.h"
#include <QApplication>
#include <QRect>
#include <QDesktopWidget>

MessageBox::MessageBox(QWidget* window, string title, string message) : QMessageBox(window) {
    setModal(true);
    QMessageBox::setText(QString::fromStdString(message));
    QMessageBox::setWindowTitle(QString::fromStdString(title));
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setContentsMargins(10, 10, 25, 10);

    setStyleSheet(R"(
        QMessageBox QPushButton {
            background-color: rgb(37, 99, 235);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QMessageBox QPushButton:hover {
            background-color: rgb(59, 130, 246);
            color: white;
        }
        QMessageBox QPushButton:pressed {
            background-color: rgb(29, 78, 216);
        }
        QMessageBox QPushButton:disabled {
            background-color: rgb(30, 64, 175);
            color: rgb(191, 219, 254);
        }
        QMessageBox QPushButton:checked {
            background-color: rgb(59, 130, 246);
            color: white;
            border: 1px solid rgb(191, 219, 254);
        }
        QMessageBox QPushButton:pressed:checked {
            background-color: rgb(76, 29, 149);
            color: white;
            border: 1px solid rgb(149, 102, 250);
        }
    )");
}

void MessageBox::setText(string message) {
    QMessageBox::setText(QString::fromStdString(message));
}
