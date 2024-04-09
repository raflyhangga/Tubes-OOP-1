#include "tubesoop1/grid/grid.h"
#include "tubesoop1/grid/location.h"

using namespace std;

template <class T> inline int Grid<T>::defaultWidth = 10;
template <class T> inline int Grid<T>::defaultHeight = 10;

template <class T>
inline Grid<T>::Grid() : Grid<T>(Grid<T>::defaultHeight, Grid<T>::defaultWidth) {}

template <class T>
inline Grid<T>::Grid(int row, int col) {
    if (row < 0 || col < 0) {
        throw invalid_argument("Row and column must be nonnegative.");
    }

    element = vector<vector<T>>(row, vector<T>(col));
    isFilled = vector<vector<bool>>(row, vector<bool>(col, 0));


    countFilled = 0;
    countNotFilled = row * col;
}

template <class T>
inline int Grid<T>::getCountFilled(){
    return countFilled;
}

template <class T>
inline int Grid<T>::getCountNotFilled(){
    return countNotFilled;
}

template <class T>
inline T Grid<T>::getElement(Location l){
    int row = l.getRow(), col = l.getCol();
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    // If it's not filled, then throw an exception.
    if (isFilled[row][col]) {
        return element[row][col];
    } else {
        throw logic_error("Element at specified position is not available.");
    }
}

template <class T>
inline void Grid<T>::setElement(Location l, T val) {
    int row = l.getRow(), col = l.getCol();
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        string message = "Row or column is out of range.\n";
        message += "Row: " + to_string(row) + ", Column: " + to_string(col) + "\n";
        message += "Grid size: " + to_string(element.size()) + "x" + to_string(element[0].size());
        throw out_of_range(message);
    }

    if (!isFilled[row][col]) {
        countFilled++;
        countNotFilled--;
        isFilled[row][col] = true;
    }

    element[row][col] = val;
}

template <class T>
inline T Grid<T>::pop(Location l) {
    int row = l.getRow(), col = l.getCol();

    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    if (!isFilled[row][col]) {
        throw logic_error("Element at specified position is not available.");
    }

    T val = element[row][col];
    isFilled[row][col] = false;

    countFilled--;
    countNotFilled++;

    return val;
}

template <class T>
inline void Grid<T>::insert(T val) {
    if (isFull())
        throw logic_error("Grid is full, cannot insert.");


    int row = (int) element.size(), col = (int) element[0].size();

    Location loc(-1, -1);
    int i, j;
    bool found = false;
    for (i = 0; i < row && !found; ++i) {
        for (j = 0; j < col && !found; ++j) {
            Location check(i, j);
            if (!isFilled[i][j]) {
                loc = check;
                found = true;
            } 
        }
    }

    setElement(loc, val);
}

template<class T>
inline bool Grid<T>::isFull() {
    return countNotFilled == 0;
}

template<class T>
inline int Grid<T>::getRow() {
    return (int) element.size();
}

template<class T>
inline int Grid<T>::getCol() {
    return (int) element[0].size();
}

template<class T>
inline T Grid<T>::operator[](Location l) {
    return getElement(l);
}


template<class T>
inline vector<Location> Grid<T>::getAllFilled() {
    vector<Location> locations;
    int row = (int) element.size(), col = (int) element[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (isFilled[i][j]) {
                locations.push_back(Location(i, j));
            }
        }
    }

    return locations;
}

template<class T>
inline Grid<T>::Iterator::Iterator(const Grid<T>* grid, int startRow, int startCol) : grid(grid), row(startRow), col(startCol) {
    skipToNextFilled();
}

template<class T>
inline bool Grid<T>::Iterator::operator!=(const Iterator& other) const {
    return row != other.row || col != other.col;
}

template<class T>
inline void Grid<T>::Iterator::skipToNextFilled() {
    if (row >= grid->element.size()) {
        return;
    }

    if (grid->isFilled[row][col]) {
        return;
    }

    do {
        col++;
        if (col >= grid->element[0].size()) {
            col = 0;
            row++;
        }
    } while (row < grid->element.size() && !grid->isFilled[row][col]);
}

template<class T>
inline typename Grid<T>::Iterator& Grid<T>::Iterator::operator++() {
    // Move to the next column
    col++;

    // If we're past the last column, move to the next row
    if (col >= grid->element[0].size()) {
        col = 0;
        row++;
    }

    skipToNextFilled();

    return *this;
}


template<class T>
inline Location Grid<T>::Iterator::operator*() const {
    return Location(row, col);
}

template<class T>
inline typename Grid<T>::Iterator Grid<T>::begin() const {
    return Iterator(this, 0, 0);
}

template<class T>
inline typename Grid<T>::Iterator Grid<T>::end() const {
    return Iterator(this, element.size(), 0);
}
