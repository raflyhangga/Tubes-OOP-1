#ifndef GRIDBUTTON_H
#define GRIDBUTTON_H

#include "tubesoop1/grid/grid.h"
#include "tubesoop1/gui/components/nicebutton.h"
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSizePolicy>
using namespace std;

template <class T>
class GridButton : public QWidget {
private:
    Grid<T>& grid;
    QVBoxLayout vLayout;
    // vector<> inputList
public:
    GridButton(Grid<T> &grid);
};


#endif