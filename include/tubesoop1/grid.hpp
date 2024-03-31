#ifndef GRID_HPP
#define GRID_HPP

#include <optional>
#include <iostream>
#include <vector>

using namespace std;



template <class T> 
class Grid {
    private:
        vector<vector<optional<T>>> element;
        int countAvailable;
        int countNotAvailable;
    public:

        /**
         * Make a grid that has a well defined row and column.
         * 
         * @param row constraint: row > 0, otherwise throw exception.
         * @param col constraint: col > 0, otherwise throw exception.
        */
        Grid(int row, int col);

        // getter countAvailable, no setter to prevent bugs
        int getCountAvailable const ();

        // getter countNotAvailable, no setter to prevent bugs
        int getCountNotAvailable const ();
        
        // getter element at a certain row and column.
        int getElement const (int row, int col);

        // element setter at a certain row and column.
        void setElement(int row, int col, T val);

};

#endif