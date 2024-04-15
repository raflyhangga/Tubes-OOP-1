#include "tubesoop1/cli/command/bangun.h"
#include "tubesoop1/cli/command/command_exception.h"
#include <tubesoop1/building/bangunan_exception.h>
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


    // Build the building
    try {
        building->build(*walikota);
        cout << "Bangunan berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    } catch (MissingResourcesException &e) {
        map<string, int> &missingResources = e.getMissingResources();
        cout << "Bangunan gagal dibangun, karena sumber daya kurang: " << endl;
        int i = 1;
        for (auto &[resource, quantity]: missingResources) {
            cout << "\t" << i << ". " << resource << ": " << quantity << endl;
            ++i;
        }
    }

}