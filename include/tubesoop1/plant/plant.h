#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <vector>
#include "tubesoop1/resource/creature.h"
using namespace std;

// <ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>
class Plant:public Creature
{
protected:
    int durationToHarvest;
    int age;
public:
    Plant() = default;
    Plant(string code, string name, int price, int durationToHarvest, vector<Product*> drops);
    void setAge(int age);
    int getAge();
    virtual ~Plant();
    friend ostream &operator<<(ostream &os, const Plant &a);
    friend istream &operator>>(istream &is, Plant &a);
    // Plant(Plant&);
    // Plant& operator==(Plant&);
};



#endif
// class TeakTree: public MaterialPlant{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Resource&> hasil_panen;
    
//         TeakTree();
//         TeakTree(int);
//         TeakTree(TeakTree&);
// };
// class SandalwoodTree: public MaterialPlant{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Resource&> hasil_panen;
    
//         SandalwoodTree();
//         SandalwoodTree(int);
//         SandalwoodTree(SandalwoodTree&);
// };
// class AloeTree: public MaterialPlant{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Resource&> hasil_panen;
    
//         AloeTree();
//         AloeTree(int);
//         AloeTree(AloeTree&);
// };
// class IronwoodTree: public MaterialPlant{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Resource&> hasil_panen;
    
//         IronwoodTree();
//         IronwoodTree(int);
//         IronwoodTree(IronwoodTree&);
// };


// class AppleTree: public FruitPlant{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Resource&> hasil_panen;  
    
//         AppleTree();
//         AppleTree(int);
//         AppleTree(AppleTree&);
// };
// class OrangeTree: public FruitPlant{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Resource&> hasil_panen;
    
//         OrangeTree();
//         OrangeTree(int);
//         OrangeTree(OrangeTree&);
// };
// class BananaTree: public FruitPlant{
//     public:
//         static string kode_huruf;
//         static string name;
//         static int price;
//         static vector<Resource&> hasil_panen;
    
//         BananaTree();
//         BananaTree(int);
//         BananaTree(BananaTree&);
// };

// Material Plant
//   Teak Tree -> 1 Teak Wood
//   Sandalwood Tree -> 1 Sandalwood Wood
//   Aloe Tree -> 1 Aloe Wood
//   Ironwood Tree -> 1 Ironwood Wood
// Fruit Plant
//   Apple Tree -> 1 Apple
//   Orange Tree -> 1 Orange
//   Banana Tree -> 1 Banana