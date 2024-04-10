#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <vector>

#include <tubesoop1/player/player.h>
#include <tubesoop1/quantifiable/quantifiable.h>
#include <tubesoop1/product/product.h>
#include <tubesoop1/resource/resource.h>

using namespace std;

class Building : public Resource
{
private:
    vector<Quantifiable<ProductMaterial*>> recipe;

public:
    Building(string code, string name, int price, const vector<Quantifiable<ProductMaterial*>> &recipe);
    void printBuildingInfo() const;
    void build(Player &p);
    void addMaterial(const ProductMaterial &material, int quantity);

    void taken(TakerVisitor* t);
};

#endif
