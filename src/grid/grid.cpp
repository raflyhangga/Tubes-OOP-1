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
    isAvailable = vector<vector<bool>>(row, vector<bool>(col, true));
    countAvailable = row * col;
    countNotAvailable = 0;
}

template <class T>
inline int Grid<T>::getCountAvailable(){
    return countAvailable;
}

template <class T>
inline int Grid<T>::getCountNotAvailable(){
    return countNotAvailable;
}

template <class T>
inline T Grid<T>::getElement(Location l){
    int row = l.getRow(), col = l.getCol();
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    // If it is not available means that it havent been set.
    if (!isAvailable[row][col]) {
        return *element[row][col];
    } else {
        throw logic_error("Element at specified position is not available.");
    }
}

template <class T>
inline void Grid<T>::setElement(Location l, T val) {
    int row = l.getRow(), col = l.getCol();
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    if (isAvailable[row][col]) {
        countAvailable--;
        countNotAvailable++;
        isAvailable[row][col] = false;
    }

    element[row][col] = val;
}

template <class T>
inline T Grid<T>::pop(Location l) {
    int row = l.getRow(), col = l.getCol;

    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    if (!element[row][col].has_value()) {
        throw logic_error("Element at specified position is not available.");
    }

    T val = *element[row][col];
    isAvailable[row][col] = false;

    countAvailable++;
    countNotAvailable--;

    return val;
}

template <class T>
inline void Grid<T>::insert(T val) {
    if (isFull())
        throw logic_error("Grid is full, cannot insert.");

    int row = (int) element.size(), col = (int) element[0].size();

    Location loc(-1, -1);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            Location check(i, j);
            if (isAvailable[i][j]) {
                loc = check;
                break;
            } 
        }
    }


    setElement(loc, val);
}

template<class T>
inline bool Grid<T>::isFull() {
    return countAvailable == 0;
}

template<class T>
inline T Grid<T>::operator[](Location l) {
    return getElement(l);
}


template<class T>
inline vector<Location> Grid<T>::getAllAvaiable() {
    vector<Location> locations;
    int row = (int) element.size(), col = (int) element[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (isAvailable[i][j]) {
                locations.push_back(Location(i, j));
            }
        }
    }

    return locations;
}

template<class T>
inline Grid<T>::Iterator::Iterator(const Grid<T>* grid, int startRow, int startCol) : grid(grid), row(startRow), col(startCol) {
    skipToNextAvailable();
}

template<class T>
inline bool Grid<T>::Iterator::operator!=(const Iterator& other) const {
    return row != other.row || col != other.col;
}

template<class T>
inline void Grid<T>::Iterator::skipToNextAvailable() {
    int row = grid->element.size(), col = grid->element[0].size();

    while (row < grid->element.size() && col < grid->element[0].size() && !grid->isAvailable[row][col]) {
        col++;
        if (col == grid->element[0].size()) {
            col = 0;
            row++;
        }
    }
}

template<class T>
inline typename Grid<T>::Iterator& Grid<T>::Iterator::operator++() {
    col++;
    if (col == grid->element[0].size()) {
        col = 0;
        row++;
    }

    skipToNextAvailable();
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
