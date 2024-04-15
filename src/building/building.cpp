#include "tubesoop1/building/building.h"
#include "tubesoop1/building/bangunan_exception.h"
#include "tubesoop1/player/walikota.h"
#include <map>

Building::Building(string code, string name, int price, const vector<Quantifiable<ProductMaterial *>> &recipe) : Resource(code, name, price),
                                                                                                                 recipe(recipe)
{
}

void Building::printBuildingInfo() const
{
    cout << name << " ("; 
    for (const auto &quantifiableProduct : recipe)
    {
        const ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();

        string formattedName = product.getName();
        // lowercase all characters. change _ to space
        for (char &c : formattedName){
            if (c == '_') c = ' ';
            else c = tolower(c);
        }

        cout << formattedName << " " << quantity;
        if (&quantifiableProduct != &recipe.back())
        {
            cout << ", ";
        }
    }
    cout << ")" << endl;
}

string Building::getFormattedBuildingInfo(){
    string info = to_string(price) + " gulden, ";
    for (const auto &quantifiableProduct : recipe)
    {
        const ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();
        string formattedName = product.getName();

        // lowercase all characters. change _ to space
        for (char &c : formattedName){
            if (c == '_') c = ' ';
            else c = tolower(c);
        }

        info += to_string(quantity) + " " + formattedName;
        if (&quantifiableProduct != &recipe.back())
        {
            info += ", ";
        }
    }
    return info;
}

void Building::addMaterial(ProductMaterial &material, int quantity)
{
    ProductMaterial *materialPtr = &material;
    Quantifiable<ProductMaterial *> quantifiable(materialPtr, quantity);

    recipe.push_back(quantifiable);
}

void Building::build(Player &p)
{
    // Check if there is an available slot for building
    if (p.getInventory().isFull())
    {
        throw SlotNotAvailableException();
    }

    map<string, int> missingResources;


    // Check if the player has enough resources and money to build the building
    Grid<Resource *> &playerInventory = p.getInventory();
    for (const auto &quantifiableProduct : recipe)
    {
        const ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();

        int availableQuantity = 0;
        for (const auto &location : playerInventory)
        {
            Resource *res = playerInventory.getElement(location);


            // Below is commented out and fixed by @ganadipa
            // if (res && res == &product)
            // {
            //     availableQuantity++;
            // }

            if (res->getCode() == product.getCode())
            {
                availableQuantity++;
            }
        }

        if (availableQuantity < quantity)
        {
            missingResources[product.getName()] = quantity - availableQuantity;
        }
    }

    if (!missingResources.empty())
    {
        throw MissingResourcesException(missingResources);
    }

    // Remove resources used for building from player's inventory
    for (const auto &quantifiableProduct : recipe)
    {
        ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();

        // Remove the specified quantity of product from player's inventory
        p.removeInventory(product, quantity);
    }

    // Add the building to the player's inventory
    p.putInventory(*this);
}

void Building::taken(TakerVisitor* t){
    t->take(this);
}

vector<Quantifiable<ProductMaterial *>> Building::getRecipe() const
{
    return recipe;
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
