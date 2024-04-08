#include <tubesoop1/grid/griddrawer.h>
#include <tubesoop1/grid/grid.h>
#include <iostream>
#include <iomanip>
#include <tubesoop1/icosihexastring/icosihexastring.h>

using namespace std;

template <class T>
inline GridDrawerCLI<T>::GridDrawerCLI(Grid<T> &grid) : grid(grid) {}

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
            cout << ' ' << *el << " |";
        } catch (const exception& e) {
            cout << "     |";
        }
    }
    cout << '\n';
}

template <class T>
inline void GridDrawerCLI<T>::draw() {
    cout << "\n    ";
    for (int i = 0; i < (this->grid).getCol(); i++) {
        cout << "  "; cout << (IcosiHexaString) i << "   ";
    }
    cout << '\n';

    for (int i = 0; i < (this->grid).getRow(); i++) {
        cout << "   "; drawRowLine();

        // draw contents with padding 1 -> 01 
        cout << setfill('0') << setw(2) << i + 1 << ' ';
        drawContents(i);
    }
    cout << "   "; drawRowLine();
}