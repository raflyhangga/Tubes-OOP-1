#include "resepbangunan.h"

// User defined constructor
ResepBangunan::ResepBangunan(string kodeHuruf, string name, const vector<Material>& materials, int price)
    : kodeHuruf(kodeHuruf), name(name), materials(materials), price(price) {}

// Print material info, the output will be (50 gulden, teak wood 1, sandal wood 1
void ResepBangunan::printMaterialInfo() {
    cout<<"(";
    for (const auto& material : materials) {
        cout << material;
        if(&material != &materials.back()) cout << ", ";
    }
    cout << ")";
}

// Add material into recipe
ResepBangunan& ResepBangunan::operator+=(const Material& material) {
    materials.push_back(material);
    return *this;
}

// Copy constructor
ResepBangunan::ResepBangunan(const ResepBangunan& other)
    : kodeHuruf(other.kodeHuruf), name(other.name), materials(other.materials), price(other.price) {}
