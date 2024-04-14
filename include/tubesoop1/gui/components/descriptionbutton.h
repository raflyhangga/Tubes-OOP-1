#ifndef DESCRIPTION_BUTTON_H
#define DESCRIPTION_BUTTON_H

#include <tubesoop1/gui/components/nicebutton.h>
#include <string>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <iostream>
using namespace std;

class DescriptionButton : public NiceButton {
    Q_OBJECT
private:
    QLabel numberLabel;
    QLabel titleLabel;
    QLabel descriptionLabel;

    QGridLayout gridLayout;

public:
    DescriptionButton();
    DescriptionButton(string number, string title, string description);
};


#endif