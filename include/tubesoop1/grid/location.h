#ifndef LOCATION_H
#define LOCATION_H

#include <utility>
#include <iostream>

using namespace std;

class Location: pair<int, int> {
    public:
        Location();
        Location(int row, int col);
        int getRow() const;
        int getCol() const;

        bool operator==(const Location& location) const;

        friend istream& operator>>(istream& is, Location& location);
        friend ostream& operator<<(ostream& os, Location& location);
        friend ostream &operator<<(ostream &os, const Location &location);
};

#endif