#include "tubesoop1/cli/command/bangun.h"
#include "tubesoop1/cli/command/command_exception.h"
Bangun::Bangun(State& state): Command(state) {}

void Bangun::execute(Petani* petani) {
    throw CommandNotAllowedException("BANGUN");
}
void Bangun::execute(Peternak* peternak) {
    throw CommandNotAllowedException("BANGUN");
}

void Bangun::execute(Walikota* walikota) {
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    auto &recipeMap = state.getRecipeMap();

    // Print list of resep bangunan
    int number = 1;
    for (auto &[f, s]: recipeMap) {
        cout << "\t" << number << ". ";
        s->printBuildingInfo();

        ++number;
    }

    cout << "Bangunan yang ingin dibangun: ";
    string buildingName;
    cin >> buildingName;

    map<string, int> needs;
    vector<Quantifiable<ProductMaterial *>> recipe;
    Building *building;
    try {
        building = recipeMap.at(buildingName);
        recipe = building->getRecipe();
    } catch (const out_of_range &e) {
        throw BuildingNotFoundException();
    }

    /**
     * This handles the case to check whether the player has enough resources to build the building
     * @ref src/building/building.cpp - update: removed procedures to handle enough resources or not in there.
    */

    for (auto &quantifiableProduct: recipe) {
        const ProductMaterial &product = *quantifiableProduct.getValue();
        const int quantity = quantifiableProduct.getQuantity();
        needs[product.getName()] = quantity;
    }


    for (const auto &loc: walikota->getInventory()) {
        Resource *r = walikota->getInventory().getElement(loc);
        string itemName = r->getName();
        if (needs.find(itemName) != needs.end()) {
            needs[itemName] -= 1;
        }
    }

    bool ableToBuild = true;
    int missingMoney = building->getPrice() - walikota->getMoney();
    if (missingMoney > 0) {
        ableToBuild = false;
    }

    vector<Quantifiable<string>> missingResources;
    for (auto &[item, quantity]: needs) {
        if (quantity > 0) {
            string itemName = item;
            ableToBuild = false;
            missingResources.push_back(Quantifiable<string>(itemName, quantity));
        }
    }

    if (!ableToBuild) {
        cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

        if (missingMoney > 0) {
            cout << missingMoney << " gulden";
            if (!missingResources.empty()) {
                cout << ", serta ";
            }
        }

        for (auto &quantifiable: missingResources) {
            cout << quantifiable.getQuantity() << " " << quantifiable.getValue();
            if (&quantifiable != &missingResources.back()) {
                cout << ", ";
            } else {
                cout << ".";
            }
        }
        cout << '\n';
        return;
    }

    // Build the building
    building->build(*walikota);
}