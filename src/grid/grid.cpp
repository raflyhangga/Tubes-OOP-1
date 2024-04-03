#include "tubesoop1/grid/grid.hpp"

using namespace std;

template <class T>
Grid<T>::Grid(int row, int col) {
    if (row <= 0 || col <= 0) {
        throw std::invalid_argument("Row and column must be greater than 0.");
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
int Grid<T>::getElement(int row, int col){
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw out_of_range("Row or column is out of range.");
    }

    if (element[row][col].has_value()) {
        return *element[row][col];
    } else {
        throw std::logic_error("Element at specified position is not available.");
    }
}

template <class T>
void Grid<T>::setElement(int row, int col, T val) {
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw std::out_of_range("Row or column is out of range.");
    }

    if (!element[row][col].has_value()) {
        countAvailable--;
        countNotAvailable++;
    }

    element[row][col] = val;
}

template <class T>
T Grid<T>::pop(int row, int col) {
    if (row < 0 || row >= element.size() || col < 0 || col >= element[0].size()) {
        throw std::out_of_range("Row or column is out of range.");
    }

    if (!element[row][col].has_value()) {
        throw std::logic_error("Element at specified position is not available.");
    }

    T val = *element[row][col];
    element[row][col].reset();
    countAvailable++;
    countNotAvailable--;

    return val;
}

