#ifndef ICOSIHEXASTRING_H
#define ICOSIHEXASTRING_H

#include <iostream>
#include <string>

using namespace std;

class IcosiHexaString {
    private:
        string str;
    public:
        IcosiHexaString(int val);

        friend ostream& operator<<(ostream &os, const IcosiHexaString& str);
};

ostream& operator<<(ostream& os, const IcosiHexaString& string) {
    os << string.str;
    return os;
}

#endif