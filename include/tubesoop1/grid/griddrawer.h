#ifndef GRIDDRAWER_H
#define GRIDDRAWER_H

#include "grid.h"


template <class T>
class GridDrawer {
    protected:
        Grid<T> grid;
    public:
        virtual void draw() = 0;
};

template <class T>
class GridDrawerCLI: public GridDrawer<T> {
    private:
        Grid<T> &grid;
        void drawRowLine();
        void drawContents(int row);
    public:
        GridDrawerCLI(Grid<T> &grid);
        void draw();
};


#endif