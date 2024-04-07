#ifndef GRIDBUTTON_H
#define GRIDBUTTON_H

#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/gui/components/locationlabel.h"
#include "tubesoop1/gui/components/nicebutton.h"
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
using namespace std;

template <class T>
class GridButton : public QWidget {
private:
    Grid<T>& grid;
    QVBoxLayout *vLayout;
    
    // Just to make sure we can free the memory later.
    vector<NiceButton*> buttonList;
    vector<QHBoxLayout*> hLayoutList; 
    vector<LocationLabel*> labelList;
public:
    GridButton(Grid<T> &grid);
};


#endif