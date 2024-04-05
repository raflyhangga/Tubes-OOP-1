#include <tubesoop1/icosihexastring/icosihexastring.h>
#include <exception>

using namespace std;

class MustNonnegativeException: public exception {
    public:
        string what() {
            return "value parameter must be a nonegative integer.";
        }
};

class MustUppercaseAlphabetException: public exception {
    public:
        string what() {
            return "value parameter must be a sting consist of uppercase alphabet only.";
        }
};

IcosiHexaString::IcosiHexaString(int val) {
    if(val < 0) throw MustNonnegativeException();
    
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

IcosiHexaString::IcosiHexaString(string s) {
    for (auto &c: s) {
        if (c < 'A' || c > 'Z') {
            throw MustUppercaseAlphabetException();
        }
    }


    str = s;
}


IcosiHexaString::operator int() const {
    int val = 0;
    for (int i = 0; i < str.size() - 1; i++) {
        val += (str[i] - 'A' + 1);
        val *= 26;
    }
    val += str[str.size() - 1] - 'A';
    return val;
}


ostream& operator<<(ostream& os, const IcosiHexaString& icosi) {
    os << icosi.str;
    
    return os;
}

