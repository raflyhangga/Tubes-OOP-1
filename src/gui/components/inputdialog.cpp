#include "tubesoop1/gui/components/inputdialog.h"
#include "tubesoop1/gui/components/messagebox.h"
#include "tubesoop1/resource/resourcefactory_exception.h"
#include <QMessageBox>

InputDialog::InputDialog(QMainWindow* window, string title, string label) : QInputDialog(window){
    // make it based on nice button and main window
    setStyleSheet(R"(
        QInputDialog {
            background-color: rgb(2, 6, 23);
            color: white;
            font-size: 17px;
            font-weight: bold;
        }
        QInputDialog QLabel {
            color: white;
        }
        QInputDialog QComboBox {
            color: white;
            background-color: rgb(17, 24, 39);
            border-radius: 15px;
        }
        QInputDialog QComboBox::item {
            color: white;
        }
        QInputDialog QComboBox::item:selected {
            color: white;
        }
        QInputDialog QPushButton {
            background-color: rgb(124, 58, 237);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QInputDialog QPushButton:hover {
            background-color: rgb(139, 92, 246);
            color: white;
        }
        QInputDialog QPushButton:pressed {
            background-color: rgb(91, 33, 182);
        }
    )");

    setContentsMargins(10, 10, 10, 10);
}