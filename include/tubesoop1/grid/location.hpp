#ifndef LOCATION_H
#define LOCATION_H

#include <utility>
#include <iostream>

using namespace std;

class Location: pair<int, int> {
    public:
        inline Location();
        inline Location(int row, int col);
        inline int getRow() const;
        inline int getCol() const;

        friend istream& operator>>(istream& is, Location& location);
};

#endif