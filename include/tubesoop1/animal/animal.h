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
    public:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
        Cow();
        Cow(int);
        Cow(Cow&);
};
class Sheep:public Herbivora{
    public:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
        Sheep();
        Sheep(int);
        Sheep(Sheep&);
};
class Horse:public Herbivora{
    public:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
        Horse();
        Horse(int);
        Horse(Horse&);
};
class Rabbit:public Herbivora{
    public:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
        Rabbit();
        Rabbit(int);
        Rabbit(Rabbit&);
};

class Snake:public Karnivora{
    public:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
        Snake();
        Snake(int);
        Snake(Snake&);
};

class Chicken:public Omnivora{
    public:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
        Chicken();
        Chicken(int);
        Chicken(Chicken&);
};
class Duck:public Omnivora{
    public:
        static string kode_huruf;
        static string name;
        static int price;
        static vector<Resource&> hasil_panen;
        Duck();
        Duck(int);
        Duck(Duck&);
};

#endif