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
};


#endif