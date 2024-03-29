#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "tubesoop1/txtparser/txtparser.h"

template <class T>
inline vector<T> TxtParser::fromtxt(string path)
{
    vector<T> t;
    ifstream file(path);
    if (file.is_open())
    {
        int i = 0;
        while (!file.eof())
        {
            t.push_back(T());
            file >> t[i];
            i++;
        }
        file.close();
        return t;
    }
    else
    {
        throw invalid_argument("File not found");
    }
}

template <class T>
inline void TxtParser::totxt(string path, vector<T> &t)
{
    ofstream file(path);
    if (file.is_open())
    {
        for (int i = 0; i < t.size(); i++)
        {
            file << i + 1 << " "; // ID
            file << t[i] << endl;
        }
        file.close();
    }
    else
    {
        throw invalid_argument("File not found");
    }
}
