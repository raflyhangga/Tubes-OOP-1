#ifndef ICOSIHEXASTRING_H
#define ICOSIHEXASTRING_H

#include <iostream>
#include <string>

using namespace std;

/**
 * Used for typecasting from int:
 *  usage: (IcosiHexaString) 12;
*/
class IcosiHexaString {
    private:
        string str;

    public:
        IcosiHexaString(int val);

        IcosiHexaString(string s);
        
        operator int() const;



        friend ostream& operator<<(ostream &os, const IcosiHexaString& str);
};


#endif