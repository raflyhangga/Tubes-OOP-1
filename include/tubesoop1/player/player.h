#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

#define DEFAULT_USERNAME "steve"
#define DEFAULT_BERAT_BADAN 0
#define DEFAULT_UANG 0

/*
* Abstract class yang menangani jenis class seperti `Petani`, `Peternak`, `Walikota`
*/
class Player{
    private:
        string username;
        int beratBadan;
        int uang;
    public:
        Player(string,int,int);
};



#endif