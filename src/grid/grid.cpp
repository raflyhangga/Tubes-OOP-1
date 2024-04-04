#include "tubesoop1/grid/grid.hpp"
#include "tubesoop1/grid/location.hpp"

using namespace std;

template <class T>
Grid<T>::Grid(int row, int col) {
    if (row <= 0 || col <= 0) {
        throw invalid_argument("Row and column must be greater than 0.");
    }

    element = vector<vector<optional<T>>>(row, vector<optional<T>>(col));
    countAvailable = row * col;
    countNotAvailable = 0;
}

template <class T>
int Grid<T>::getCountAvailable(){
    return countAvailable;
}

template <class T>
int Grid<T>::getCountNotAvailable(){
    return countNotAvailable;
}

template <class T>
T Grid<T>::getElement(Location l){
    int row = l.getRow(), col = l.getCol();
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    if (element[row][col].has_value()) {
        return *element[row][col];
    } else {
        throw logic_error("Element at specified position is not available.");
    }
}

template <class T>
void Grid<T>::setElement(Location l, T val) {
    int row = l.getRow(), col = l.getCol();
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    if (!element[row][col].has_value()) {
        countAvailable--;
        countNotAvailable++;
    }

    element[row][col] = val;
}

template <class T>
T Grid<T>::pop(Location l) {
    int row = l.getRow(), col = l.getCol;

    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    if (!element[row][col].has_value()) {
        throw logic_error("Element at specified position is not available.");
    }

    T val = *element[row][col];
    element[row][col].reset();
    countAvailable++;
    countNotAvailable--;

    return val;
}

template <class T>
bool Grid<T>::isAvailable(Location l) {
    return !element[row][col].has_value();
}

template <class T>
void Grid<T>::insert(T val) {
    if (isFull)
        throw logic_error("Grid is full, cannot insert.");

    int row = (int) element.size(), col = (int) element[0].size();

    Location loc(-1, -1);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            Location check(i, j);
            if (isAvailable(check)) {
                loc = check;
                break;
            } 
        }
    }
}

template<class T>
bool Grid<T>::isFull() {
    return countAvailable == 0;
}
