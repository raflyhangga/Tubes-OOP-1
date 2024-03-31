#include "tubesoop1/icosihexastring.h"

using namespace std;

class IcosiHexaStringException: public exception {
    public:
        string what() {
            return "value parameter must be a nonegative integer.";
        }
};

IcosiHexaString::IcosiHexaString(int val) {
    if(val < 0) throw IcosiHexaStringException();
    
    string reversed;
    reversed += (val % 26) + 'A';
    while (val/26 > 0) {
        val /= 26;
        reversed += ((--val) % 26) + 'A';
    }

    str = "";
    for (int i = reversed.size() - 1; i >= 0; i--) {
        str += reversed[i];
    }
}

ostream& operator<<(ostream& os, const IcosiHexaString& string) {
    os << string.str;
    return os;
}

