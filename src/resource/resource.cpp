#include "tubesoop1/resource/resource.h"

Resource::Resource(string code, string name, int price)
    : code(code), name(name), price(price) {}

Resource::~Resource() {}


string Resource::getCode() const {
    return code;
}

string Resource::getName() const {
    return name;
}

int Resource::getPrice() const {
    return price;
}

bool Resource::operator==(Resource& a){
    return
        this->code == a.code &&
        this->name == a.name &&
        this->price == a.price;
}

ostream &operator<<(ostream &os, const Resource &res) {
    os << res.code;
    return os;
}


// template <class T>
// T* Resource::taken<T>(TakerVisitor* t){
//     cout << "resource" << endl;
//     // return t->take(this);
//     return this;
// }

// TOdo: Delete this main function if not needed (only for testing purpose)
// int main() {
//     // Create instances of Resource
//     Resource res1("001", "ABC", "Resource 1", 50);
//     Resource res2("002", "DEF", "Resource 2", 100);
//     Resource res3("003", "GHI", "Resource 3", 150);

//     // Print information about the resources
//     std::cout << "Resource 1: " << res1.getName() << " - Price: " << res1.getPrice() << std::endl;
//     std::cout << "Resource 2: " << res2.getName() << " - Price: " << res2.getPrice() << std::endl;
//     std::cout << "Resource 3: " << res3.getName() << " - Price: " << res3.getPrice() << std::endl;

//     return 0;
// }