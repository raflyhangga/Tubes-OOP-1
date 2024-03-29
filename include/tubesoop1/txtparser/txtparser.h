#ifndef TXT_PARSER_H
#define TXT_PARSER_H

class TxtParser
{
public:
    template <class T>
    static vector<T> fromtxt(string path);
    template <class T>
    static void totxt(string path, vector<T> &t);
};

#endif