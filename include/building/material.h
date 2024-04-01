#ifndef MATERIAL_H
#define MATERIAL_H
#include <iostream>
using namespace std;
#include "../product/product.h"

class Material
{
private:
    Product name;
    int quantity;

public:
    // Allocation of memory for the name object User defined constructor
    Material(Product &name, int quantity);
    friend ostream &operator<<(ostream &os, const Material &a);
    // Setter to insert material
    friend istream &operator>>(istream &is, Material &a);
};

#endif