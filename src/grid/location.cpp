#include <tubesoop1/grid/location.hpp>
#include <tubesoop1/icosihexastring.h>

using namespace std;

inline Location::Location(){

}

inline Location::Location(int row, int col) {
    first = row;
    second = col;
}

inline int Location::getRow() const {
    return first;
}

inline int Location::getCol() const {
    return second;
}

inline istream &operator>> (istream &is, Location &location) {
    string str; is >> str;
    // handles input like "A01"
    

    string icosi = "";
    for (int i = 0; i < str.size(); ++i) {
        int code = (int) str[i];
        if (code >= 65 && code <= 90) {
            icosi += str[i];
        } else {
            break;
        }
    }

    IcosiHexaString icosiHexaString(icosi);

    location.first = (int) icosiHexaString; 
    location.second = stoi(str.substr(icosi.size()));
    return is;
}