#ifndef MATERIAL_H
#define MATERIAL_H
#include <iostream>
using namespace std;
#include "../product/product.h"
using namespace std;

class Material
{
private:
    // Todo: Change product to type material product, pending: rayhan
    Product name;
    int quantity;

public:
    Material(Product &name, int quantity);
    friend ostream &operator<<(ostream &os, const Material &a);
    // Setter to insert material
    friend istream &operator>>(istream &is, Material &a);
};

#endif