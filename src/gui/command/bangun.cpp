#include "tubesoop1/building/bangunan_exception.h"
#include "tubesoop1/gui/command/bangun.h"
#include "tubesoop1/gui/command/command_exception.h"
#include "tubesoop1/gui/components/messagebox.h"
#include "tubesoop1/gui/components/choicedialog.h"
#include <QInputDialog>
#include <QStringList>
#include <QString>
#include <tubesoop1/building/bangunan_exception.h>
#include <QObject>
#include <utility>

Bangun::Bangun(State& state, MainWindow& window): Command(state, window) {}

void Bangun::execute(Petani* petani) {
    MessageBox(&window, "Bangun", "Anda tidak dapat membangun bangunan!").exec();
}
void Bangun::execute(Peternak* peternak) {
    MessageBox(&window, "Bangun", "Anda tidak dapat membangun bangunan!").exec();
}

void Bangun::execute(Walikota* walikota) {
    auto &recipeMap = state.getRecipeMap();
    QVector<pair<string, string>> choices;
    vector<string> indexedKeys;
    
    for (auto &[key, building]: recipeMap) {
        string info = building->getFormattedBuildingInfo();
        choices.append(pair<string, string>(formatName(key), info));
        indexedKeys.push_back(key);
    }

    ChoiceDialog choiceDialog = ChoiceDialog(&window, choices, "Bangun", "Daftar Resep Bangunan", "Pilih jenis bangunan yang ingin dibangun");
    choiceDialog.connect(&choiceDialog, &ChoiceDialog::choiceMade, [&](int index){
        
        map<string, int> needs;
        vector<Quantifiable<ProductMaterial *>> recipe;
        Building *building;
        string buildingName = indexedKeys[index];
        try {
            building = recipeMap.at(buildingName);
            recipe = building->getRecipe();
        } catch (const out_of_range &e) {
            throw BuildingNotFoundException();
        }

        // Build the building
        try {
            building->build(*walikota);
            MessageBox(&choiceDialog, "Bangun", "Bangunan berhasil dibangun dan telah menjadi hak milik walikota!").exec();
            choiceDialog.close();
        } catch (logic_error &e) {
            MessageBox(&choiceDialog, "Bangun", "Bangunan gagal dibangun karena walikota tidak mempunyai inventory yang kosong.").exec();
        } catch (MissingResourcesException &e) {
            map<string, int> &missingResources = e.getMissingResources();
            string message = "Bangunan gagal dibangun, karena sumber daya kurang: \n";
            int i = 1;
            for (auto &[resource, quantity]: missingResources) {
                message += "   " + to_string(i) + ". " + to_string(quantity) + " " + formatName(resource) + " \n";
                ++i;
            }
            MessageBox(&choiceDialog, "Bangun", message).exec();
        }

    });
    choiceDialog.exec();



}