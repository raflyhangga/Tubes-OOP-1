#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

typedef vector<string> Attributes;

class FileReader {
    private:
        map<string, string> lineData;
        Attributes attributes;

    public:
        FileReader(string filename, int num_column);

        FileReader(string filename, Attributes attr);


        // readline method reads the current line of the file and put it in the lineData
        // if line is empty, sets done flag to true;
        void readline();

        // gets the data inside the linedata, if attr is not a key in the linedata, throw exception.
        void get(string attr);

        // gets the data inside the linedata, if index is out of bounds, throw exception.
        void get(int index);

        bool done;
};

#endif