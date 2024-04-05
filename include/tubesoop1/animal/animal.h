#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/plant/plant.h"
#include <vector>
using namespace std;

// <ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>
class Animal: public Resource
{
private:
    int weightToHarvest;

public:
    friend ostream &operator<<(ostream &os, const Animal &a);
    friend istream &operator>>(istream &is, Animal &a);
};

class Herbivora: public Animal {
    public:
        virtual void makan(Plant&);
        virtual void makan(Product&);
};

class Karnivora: public Animal {
    public:
        virtual void makan(Animal&);
        virtual void makan(Product&);
};

class Omnivora: public Animal {
    public:
        virtual void makan(Animal&);
        virtual void makan(Plant&);
        virtual void makan(Product&);
};

class Cow:public Herbivora{
    private:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
};
class Sheep:public Herbivora{
    private:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
};
class Horse:public Herbivora{
    private:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
};
class Rabbit:public Herbivora{
    private:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
};

class Snake:public Karnivora{
    private:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
};

class Chicken:public Omnivora{
    private:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
};
class Duck:public Omnivora{
    private:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
};

#endif