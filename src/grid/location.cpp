#include <tubesoop1/grid/location.h>
#include <tubesoop1/icosihexastring/icosihexastring.h>
#include <tubesoop1/grid/location_exception.hpp>

#include <iomanip>

using namespace std;

Location::Location(){

}

Location::Location(int row, int col) {
    first = row;
    second = col;
}

int Location::getRow() const {
    return first;
}

int Location::getCol() const {
    return second;
}

istream &operator>> (istream &is, Location &location) {
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

    try {
        IcosiHexaString icosiHexaString(icosi);
        
        for (auto &c: str.substr(icosi.size())) {
            if (isalpha(c)) throw LocationException();
        }


        location.first = stoi(str.substr(icosi.size())) - 1;
        location.second = (int) icosiHexaString; 
    } catch (const exception &e){
        throw LocationException();
    }

    return is;
}

ostream &operator<<(ostream &os, Location &location) {
    IcosiHexaString icosiHexaString(location.getCol());
    os << icosiHexaString;
    os << setfill('0') << setw(2) << location.getRow() + 1 << '\n';
    return os;
}