#ifndef GRIDDRAWER_HPP
#define GRIDDRAWER_HPP

#include "grid.hpp"


template <class T>
class GridDrawer {
    private:
        Grid<T> grid;
    public:
        virtual void draw() = 0;
};

template <class T>
class GridDrawerCLI: public GridDrawer<T> {
    private:
        void drawRowLine();
        void drawContents(int row);
    public:
        GridDrawerCLI(Grid<T> grid);
        void draw();
};


#endif