#ifndef GRID_HPP
#define GRID_HPP

#include <optional>
#include <iostream>
#include <vector>
#include "location.hpp"

using namespace std;



template <class T> 
class Grid {
    private:
        vector<vector<T>> element;
        vector<vector<bool>> isAvailable;
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
        int getCountAvailable();

        // getter countNotAvailable, no setter to prevent bugs
        int getCountNotAvailable();
        
        // getter element at a certain row and column.
        T getElement(Location l);

        // element setter at a certain row and column.
        void setElement(Location l, T val);

        // Pop element at a specified location, return the element at the specified location.
        T pop(Location l);

        /**
         * Insert Element at the Top most, left most grid. 
         * Higher priority: top > left.
        */
       void insert(T val);

       bool isFull();
};

#endif