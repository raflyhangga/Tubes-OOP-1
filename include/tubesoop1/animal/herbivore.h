#ifndef HERBIVORE_H
#define HERBIVORE_H

#include <string>
#include "tubesoop1/resource/creature.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/product/productvisitorpattern.h"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/animal/animal_exception.h"
#include <vector>
using namespace std;

class Herbivore: public Animal {
    public:
        Herbivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops);
        void eat(ProductAnimal&);
        void eat(ProductFruit&);
        void eat(ProductMaterial&);
};

#endif