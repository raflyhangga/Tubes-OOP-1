#include <tubesoop1/grid/griddrawer.h>
#include <tubesoop1/grid/grid.h>
#include <iostream>

using namespace std;

template <class T>
inline GridDrawerCLI<T>::GridDrawerCLI(Grid<T> grid) {
    grid = grid;
}

template <class T>
inline void GridDrawerCLI<T>::drawRowLine() {

    cout << '+';
    for (int i = 0; i < (this->grid).getCol(); i++) {
        cout <<  "-----+";
    }
    cout << '\n';
}

template <class T>
inline void GridDrawerCLI<T>::drawContents(int row) {
    cout << '|';
    for (int i = 0; i < (this->grid).getCol(); i++) {
        try {
            T el = (this->grid).getElement(Location(row, i));
            cout << ' ' << el << " |";
        } catch (const exception& e) {
            cout << "     |";
        }
    }
    cout << '\n';
}

template <class T>
inline void GridDrawerCLI<T>::draw() {
    for (int i = 0; i < (this->grid).getRow(); i++) {
        drawRowLine();
        drawContents(i);
    }
    drawRowLine();
}