#include <tubesoop1/building/building.h>
#include <tubesoop1/building/bangunan_exception.h>


Building::Building(string code, string name, int price, const vector<Quantifiable<Product*>> &recipe):
    Resource(code,name,price),
    recipe(recipe)
{

}

// Constructor implementation
// Building::Building(string id, string code, string name, int price, const vector<Quantifiable<Product>>& recipe)
//     : Resource(code, name, price), recipe(recipe) {}

// void Building::printBuildingInfo() const {
//     cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
//     int recipeNumber = 1; // Auto-incrementing number for the recipe
//     for (const auto& quantifiableProduct : recipe) {
//         const Product& product = quantifiableProduct.getValue();
//         const int quantity = quantifiableProduct.getQuantity();
//         // Todo: Pending on rayhan class product material implementation
//         // cout << recipeNumber << ". " << product.getName() << " (" << product.getPrice() << " gulden, ";
//         // cout << product.getMaterial() << " " << product.getMaterialQuantity() << ", ";
//         recipeNumber++;
//     }
// }

// Method to add a building material to the recipe
// void Building::addMaterial(const Product& material, int quantity) {
//     Quantifiable<Product> quantifiableMaterial(material, quantity);
//     recipe.push_back(quantifiableMaterial);
// }


// void Building::build(Player& p) {
//     // Check if the player has the role of mayor
//     // if (!p.isMayor()) {
//     //     throw RoleWaliKotaException();
//     // }

//     // // Check if there is an available slot for building
//     // if (!p.hasAvailableBuildingSlot()) {
//     //     throw SlotNotAvailableException();
//     // }

//     // Check if the player has enough resources and money to build the building
//     for (const auto& quantifiableProduct : recipe) {
//         const Product& product = quantifiableProduct.getValue();
//         const int quantity = quantifiableProduct.getQuantity();

//         // Check if the player has the required quantity of materials
//         if (!p.hasResource(product.getMaterial1(), product.getMaterial1Quantity()) ||
//             !p.hasResource(product.getMaterial2(), product.getMaterial2Quantity())) {
//             throw NotEnoughMaterialException();
//         }

//         // Check if the player has enough money
//         if (p.getMoney() < product.getPrice()) {
//             throw NotEnoughMoneyException();
//         }
//     }

//     // Build the building if all checks pass
//     for (const auto& quantifiableProduct : recipe) {
//         const Product& product = quantifiableProduct.getValue();

//         // Consume resources and money
//         p.consumeResource(product.getMaterial1(), product.getMaterial1Quantity());
//         p.consumeResource(product.getMaterial2(), product.getMaterial2Quantity());
//         p.subtractMoney(product.getPrice());
//     }

//     cout << "Bangunan berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
// }

