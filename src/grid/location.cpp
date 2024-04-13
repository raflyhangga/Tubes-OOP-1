#include <tubesoop1/grid/location.h>
#include <tubesoop1/icosihexastring/icosihexastring.h>
#include <tubesoop1/grid/location_exception.h>

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

string Location::toStdString() const {
    IcosiHexaString icosiHexaString(second);
    return icosiHexaString.getString() + to_string(first + 1);
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

bool Location::operator==(const Location &location) const {
    return first == location.first && second == location.second;
}

ostream &operator<<(ostream &os, Location &location) {
    IcosiHexaString icosiHexaString(location.getCol());
    os << icosiHexaString;
    os << setfill('0') << setw(2) << location.getRow() + 1;
    return os;
}

ostream &operator<<(ostream &os, const Location &location) {
    IcosiHexaString icosiHexaString(location.getCol());
    os << icosiHexaString;
    os << setfill('0') << setw(2) << location.getRow() + 1;
    return os;
}