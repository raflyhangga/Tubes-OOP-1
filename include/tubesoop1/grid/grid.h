#ifndef GRID_H
#define GRID_H

#include <optional>
#include <iostream>
#include <vector>
#include "tubesoop1/grid/location.h"

using namespace std;

template <class T> 
class Grid {
    private:
        vector<vector<T>> element;
        vector<vector<bool>> isFilled;
        int countFilled;
        int countNotFilled;
    public:
        static int defaultWidth;
        static int defaultHeight;

        Grid();

        /**
         * Make a grid that has a well defined row and column.
         * 
         * @param row constraint: row > 0, otherwise throw exception.
         * @param col constraint: col > 0, otherwise throw exception.
        */
        Grid(int row, int col);

        // getter countAvailable, no setter to prevent bugs
        int getCountFilled();

        // getter countNotAvailable, no setter to prevent bugs
        int getCountNotFilled();
        
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

        int getRow();

        int getCol();

        T operator[](Location l);

        Grid<T>& operator+(const T &val);
        Grid<T>& operator+=(const T &val);

        vector<Location> getAllFilled();

        bool isElementFilled(Location l);

        class Iterator {
            private:
                const Grid<T>* grid;
                int row, col;

                void skipToNextFilled();

            public:
                Iterator(const Grid<T>* grid, int startRow, int startCol);

                bool operator!=(const Iterator& other) const;

                Iterator& operator++();

                Location operator*() const;
        };
    
        Iterator begin() const;

        Iterator end() const;
};

#endif