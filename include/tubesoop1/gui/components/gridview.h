#ifndef GRID_VIEW_H
#define GRID_VIEW_H

#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/gui/components/locationlabel.h"
#include "tubesoop1/gui/components/nicebutton.h"
#include "tubesoop1/gui/components/gridsignal.h"
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QtCore>

using namespace std;

template<class T>
class GridView : public GridSignal {
private:
    Grid<T>* grid;
    QVBoxLayout vLayout;
    QLabel errorLabel;
    
    // Just to make sure we can free the memory later.
    vector<QWidget*> buttonList;
    vector<QHBoxLayout*> hLayoutList; 
    vector<LocationLabel*> labelList;
public:
    GridView();
    ~GridView();
    void setGrid(Grid<T>* grid);
    void refresh();
    void clear();
    QPushButton* getWidget(Location location);

    void showError(string message);

    void setEnabled(bool enabled);
    void setCheckable(bool checkable);
};


#endif