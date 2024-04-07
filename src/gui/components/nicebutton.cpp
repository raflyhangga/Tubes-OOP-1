#include "tubesoop1/gui/components/nicebutton.h"

NiceButton::NiceButton() : QPushButton() {
    setStyleSheet(R"(
        QPushButton {
            background-color: rgb(124, 58, 237);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QPushButton:hover {
            background-color: rgb(139, 92, 246);
            color: white;
        }
        QPushButton:pressed {
            background-color: rgb(91, 33, 182);
        }
        QPushButton:disabled {
            background-color: rgb(76, 29, 149);
            color: rgb(167, 139, 250);
        }
    )");
    setCursor(QCursor(Qt::PointingHandCursor));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
NiceButton::NiceButton(string text) : NiceButton() {
    setText(QString::fromStdString(text));
}
