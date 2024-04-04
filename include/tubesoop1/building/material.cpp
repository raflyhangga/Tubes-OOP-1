#include "material.h"

// User defined constructor
Material::Material(Product& name, int quantity) : name(name), quantity(quantity) {}

ostream &operator<<(ostream &os, const Material &a) {
    // Todo: Change name.getName() to name, pending: rayhan
    os << a.quantity << " ";// << a.name.getName();
    return os;
}

// Insert material quantity
istream &operator>>(istream &is, Material &a) {
    is  >> a.quantity;
    return is;
}

