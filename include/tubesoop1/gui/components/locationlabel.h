#ifndef LOCATIONLABEL_H
#define LOCATIONLABEL_H

#include <string>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <Qt>
using namespace std;

class LocationLabel : public QLabel {
private:

public:
    LocationLabel(string &label);
};


#endif