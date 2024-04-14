#include "tubesoop1/gui/components/nicebutton.h"

NiceButton::NiceButton() : QPushButton() {
    setStyleNormal();
    setCursor(QCursor(Qt::PointingHandCursor));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
NiceButton::NiceButton(string text) : NiceButton() {
    setText(QString::fromStdString(text));
    if(text == "") setStyleEmpty();
}

void NiceButton::setStyleNormal(){
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
        QPushButton:checked {
            background-color: rgb(101, 43, 192);
            color: white;
            border: 1px solid rgb(149, 102, 250);
        }
        QPushButton:pressed:checked {
            background-color: rgb(76, 29, 149);
            color: white;
            border: 1px solid rgb(149, 102, 250);
        }
    )");
}


void NiceButton::setStyleSuccess(){
    setStyleSheet(R"(
        QPushButton {
            background-color: rgb(34, 197, 94);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QPushButton:disabled {
            background-color: rgb(21, 128, 61);
            color: rgb(220, 252, 231);
        }
        QPushButton:hover {
            background-color: rgb(74, 222, 128);
            color: white;
        }
        QPushButton:pressed {
            background-color: rgb(22, 163, 74);
        }
        QPushButton:checked {
            color: white;
            border: 2px solid rgb(220, 252, 231);
        }
        QPushButton:pressed:checked {
            background-color: rgb(22, 163, 74);
            color: white;
            border: 2px solid rgb(220, 252, 231);
        }
    )");
}


void NiceButton::setStyleFailed(){
    setStyleSheet(R"(
        QPushButton {
            background-color: rgb(225, 29, 72);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QPushButton:disabled {
            background-color: rgb(159, 18, 57);
            color: rgb(254, 205, 211);
        }
        QPushButton:hover {
            background-color: rgb(244, 63, 94);
            color: white;
        }
        QPushButton:pressed {
            background-color: rgb(159, 18, 57);
        }
        QPushButton:checked {
            color: white;
            border: 2px solid rgb(254, 205, 211);
        }
        QPushButton:checked {
            background-color: rgb(159, 18, 57);
            color: white;
            border: 2px solid rgb(254, 205, 211);
        }
    )");
}

// Normal -> Nheckable
// bg -> bg:pressed
// bg -> border bg:hover
// bg <- rgb(30, 41, 59)
void NiceButton::setStyleNormalCheckable(){
    setStyleSheet(R"(
        QPushButton {
            background-color: rgb(30, 41, 59);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QPushButton:hover {
            background-color: rgb(35, 46, 67);
            border: 1px solid rgb(139, 92, 246);
            color: rgb(167, 139, 250);
        }
        QPushButton:pressed {
            background-color: rgb(139, 92, 246);
            color: white;
        }
        QPushButton:disabled {
            background-color: rgb(76, 29, 149);
            color: rgb(167, 139, 250);
        }
        QPushButton:checked {
            background-color: rgb(101, 43, 192);
            color: white;
            border: 1px solid rgb(149, 102, 250);
        }
        QPushButton:pressed:checked {
            background-color: rgb(76, 29, 149);
            color: white;
            border: 1px solid rgb(149, 102, 250);
        }
    )");
}

// Same as normal, but the text is empty so the button is grey
void NiceButton::setStyleEmpty(){
    setStyleSheet(R"(
        QPushButton {
            background-color: rgb(15, 23, 42);
            color: white;
            border-radius: 15px;
            font-size: 15px;
            font-weight: bold;
            padding: 10px 20px;
        }
        QPushButton:hover {
            background-color: rgb(51, 65, 85);
            color: white;
        }
        QPushButton:pressed {
            background-color: rgb(91, 33, 182);
        }
        QPushButton:disabled {
            background-color: rgb(15, 23, 42);
            color: rgb(167, 139, 250);
        }
        QPushButton:checked {
            background-color: rgb(101, 43, 192);
            color: white;
            border: 1px solid rgb(149, 102, 250);
        }
        QPushButton:pressed:checked {
            background-color: rgb(76, 29, 149);
            color: white;
            border: 1px solid rgb(149, 102, 250);
        }
    )");
}