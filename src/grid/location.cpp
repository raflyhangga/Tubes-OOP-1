#include <tubesoop1/grid/location.h>
#include <tubesoop1/icosihexastring/icosihexastring.h>

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

    IcosiHexaString icosiHexaString(icosi);

    location.first = (int) icosiHexaString; 
    location.second = stoi(str.substr(icosi.size()));
    return is;
}