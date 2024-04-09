#ifndef CREATURE_H
#define CREATURE_H

#include "tubesoop1/resource/resource.h"
#include "tubesoop1/product/product.h"
#include <vector>

using namespace std;

class Creature: public Resource {
    private:
        vector<Product*> drops;
    public:
        Creature() = default;
        Creature(string code, string name, int price, vector<Product*> drops);
        Creature(Creature&);
        ~Creature();
        Creature& operator=(const Creature &);
        Creature& operator<<(Product&);
        virtual bool isHarvestable() const = 0;
        vector<Product*>& harvest();
        friend ostream& operator<<(ostream&, const Creature&);
};


#endif