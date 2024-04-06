#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "tubesoop1/resource/creature.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/plant/plant.h"
#include <vector>
using namespace std;

// <ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>
class Animal: public Creature
{
private:
    int weightToHarvest;

public:
    Animal() = default;

    Animal(string code, string name, int price, int weightToHarvest,vector<Product*> drops);

    virtual ~Animal();

    virtual int makan(Product&) = 0;

    void setWeightToHarvest(int weightToHarvest);
    int getWeightToHarvest() const;
    friend ostream &operator<<(ostream &os, const Animal &a);
    friend istream &operator>>(istream &is, Animal &a);
};

class Herbivora: public Animal {
    public:
        Herbivora(string code, string name, int price, int weightToHarvest, vector<Product*> drops);
       
        int makan(Product&);
};

class Karnivora: public Animal {
    public:
        Karnivora(string code, string name, int price, int weightToHarvest, vector<Product*> drops);

        int makan(Product&);
};

class Omnivora: public Animal {
    public:
        Omnivora(string code, string name, int price, int weightToHarvest, vector<Product*> drops);
        virtual int makan(Product&);
};

// class Cow:public Herbivora{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Product*> hasil_panen;
//         Cow();
//         Cow(int);
//         Cow(Cow&);
// };
// class Sheep:public Herbivora{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Product*> hasil_panen;
//         Sheep();
//         Sheep(int);
//         Sheep(Sheep&);
// };
// class Horse:public Herbivora{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Product*> hasil_panen;
//         Horse();
//         Horse(int);
//         Horse(Horse&);
// };
// class Rabbit:public Herbivora{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Product*> hasil_panen;
//         Rabbit();
//         Rabbit(int);
//         Rabbit(Rabbit&);
// };

// class Snake:public Karnivora{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Product*> hasil_panen;
//         Snake();
//         Snake(int);
//         Snake(Snake&);
// };

// class Chicken:public Omnivora{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Product*> hasil_panen;
//         Chicken();
//         Chicken(int);
//         Chicken(Chicken&);
// };
// class Duck:public Omnivora{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Product*> hasil_panen;
//         Duck();
//         Duck(int);
//         Duck(Duck&);
// };

#endif