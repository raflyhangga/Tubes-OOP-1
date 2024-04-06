#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "tubesoop1/resource/creature.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/product/visitorpattern.h"
#include <vector>
using namespace std;


class Animal: public Creature, public EaterVisitor
{
private:
    int weightToHarvest;
protected:
    int weight;
public:
    Animal() = default;

    Animal(string code, string name, int price, int weightToHarvest,vector<Product*> drops);

    void setWeight(int weight);

    // Visitor pattern
    void eat(Product&);
    virtual void eat(ProductAnimal&) = 0;
    virtual void eat(ProductFruit&) = 0;

    bool isHarvestable() const;
    friend ostream &operator<<(ostream &os, const Animal &a);
    friend istream &operator>>(istream &is, Animal &a);
};

#endif