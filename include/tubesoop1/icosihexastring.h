#ifndef ICOSIHEXASTRING_H
#define ICOSIHEXASTRING_H

#include <string>

using namespace std;

class IcosiHexaString {
    private:
        int numValue;
    public:
        string value;

        IcosiHexaString();

        IcosiHexaString(int val);

        bool operator>(const IcosiHexaString&);

        bool operator<(const IcosiHexaString&);

        bool operator==(const IcosiHexaString&);

        bool operator!=(const IcosiHexaString&);

        int getIntegerVaue() const;
};

#endif