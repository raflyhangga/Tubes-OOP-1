#ifndef NICEBUTTON_H
#define NICEBUTTON_H

#include <string>
#include <QPushButton>
#include <QSizePolicy>
using namespace std;

class NiceButton : public QPushButton {
public:
    NiceButton();
    NiceButton(string text);

    void setStyleEmpty();
    void setStyleNormal();
    void setStyleSuccess();
    void setStyleFailed();
    void setStyleNormalCheckable();
};


#endif