#include "tubesoop1/building/building.h"
#include "tubesoop1/building/bangunan_exception.h"
#include "tubesoop1/player/walikota.h"

Building::Building(string code, string name, int price, const vector<Quantifiable<ProductMaterial *>> &recipe) : Resource(code, name, price),
                                                                                                                 recipe(recipe)
{
}

void Building::printBuildingInfo() const
{
    cout << name << " (" << price << " gulden, ";
    for (const auto &quantifiableProduct : recipe)
    {
        const ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();
        cout << product.getName() << " " << quantity;
        if (&quantifiableProduct != &recipe.back())
        {
            cout << ", ";
        }
    }
    cout << ")" << endl;
}

void Building::addMaterial(const ProductMaterial &material, int quantity)
{
    ProductMaterial *materialPtr = const_cast<ProductMaterial *>(&material);

    Quantifiable<ProductMaterial *> quantifiable(materialPtr, quantity);

    recipe.push_back(quantifiable);
}

void Building::build(Player &p)
{
    // Check if the player has the role of walikota
    if (!dynamic_cast<Walikota *>(&p))
    {
        throw RoleWaliKotaException();
    }

    // Check if there is an available slot for building
    if (p.getInventory().isFull())
    {
        throw SlotNotAvailableException();
    }

    // Check if the player has enough money to build the building
    if (p.getMoney() < price)
    {
        throw NotEnoughMoneyException();
    }

    // Check if the player has enough resources and money to build the building
    for (const auto &quantifiableProduct : recipe)
    {
        const ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();

        int availableQuantity = 0;
        Grid<Resource *> playerInventory = p.getInventory();
        for (const auto &location : playerInventory.getAllFilled())
        {
            Resource *res = playerInventory.getElement(location);
            if (res && res == &product)
            {
                availableQuantity++;
            }
        }

        if (availableQuantity < quantity)
        {
            throw NotEnoughMaterialException();
        }
    }

    // Deduct the player's money
    p.setMoney(p.getMoney() - price);

    // Remove resources used for building from player's inventory
    for (const auto &quantifiableProduct : recipe)
    {
        const ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();

        // Remove the specified quantity of product from player's inventory
        p.removeInventory(const_cast<ProductMaterial &>(product), quantity);
    }

    // Add the building to the player's inventory
    p.putInventory(*this);

    cout << "Bangunan berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
}

// int main()
// {
//     vector<Quantifiable<ProductMaterial *>> recipe;
//     ProductMaterial material1("M1", "Material 1", 100, 10);
//     ProductMaterial material2("M2", "Material 2", 200, 20);
//     ProductMaterial material3("M3", "Material 3", 300, 30);

//     Building building("B1", "Building 1", 1000, recipe);
//     building.addMaterial(material1, 2);
//     building.addMaterial(material2, 1);
//     building.addMaterial(material3, 3);

//     building.printBuildingInfo();
//     return 0;
// }
