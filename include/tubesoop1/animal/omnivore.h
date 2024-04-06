#ifndef OMNIVORE_H
#define OMNIVORE_H

#include <string>
#include "tubesoop1/resource/creature.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/product/visitorpattern.h"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/animal/animal_exception.h"
#include <vector>
using namespace std;

class Omnivore: public Animal {
    public:
        Omnivore(string code, string name, int price, int weightToHarvest, vector<Product*> drops);
        void eat(ProductAnimal&);
        void eat(ProductFruit&);
};

#endif