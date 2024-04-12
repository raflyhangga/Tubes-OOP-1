#ifndef GRID_SIGNAL_H
#define GRID_SIGNAL_H

#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/gui/components/locationlabel.h"
#include "tubesoop1/gui/components/nicebutton.h"
#include <vector>
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QtCore>

using namespace std;

class GridSignal : public QWidget {
    Q_OBJECT
signals:
    void cellClicked(Location location);
};


#endif