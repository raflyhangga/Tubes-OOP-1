#include "../../include/tubesoop1/grid/griddrawer.hpp"
#include <iostream>

using namespace std;

template <class T>
GridDrawerCLI<T>::GridDrawerCLI(Grid<T> grid) {
    this->grid = grid;
}

template <class T>
void GridDrawerCLI<T>::drawRowLine() {
    cout << '+';
    for (int i = 0; i < grid.getCol(); i++) {
        cout <<  "-----+";
    }
    cout << '\n';
}

template <class T>
void GridDrawerCLI<T>::drawContents(int row) {
    cout << '|';
    for (int i = 0; i < grid.getCol(); i++) {
        cout << ' ' << grid.getElement(row, i) << " |";
    }
    cout << '\n';
}

template <class T>
void GridDrawerCLI<T>::draw() {
    for (int i = 0; i < grid.getRow(); i++) {
        drawRowLine()
        drawContents(i);
    }
    drawRowLine();
}