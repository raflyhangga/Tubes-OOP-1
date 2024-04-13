#include "tubesoop1/building/bangunan_exception.h"
#include "tubesoop1/gui/command/bangun.h"
#include "tubesoop1/gui/command/command_exception.h"
#include "tubesoop1/gui/components/messagebox.h"
#include "tubesoop1/gui/components/choicedialog.h"
#include <QInputDialog>
#include <QStringList>
#include <QString>
#include <QObject>

Bangun::Bangun(State& state, MainWindow& window): Command(state, window) {}

void Bangun::execute(Petani* petani) {
    MessageBox(&window, "Bangun", "Anda tidak dapat membangun bangunan!").exec();
}
void Bangun::execute(Peternak* peternak) {
    MessageBox(&window, "Bangun", "Anda tidak dapat membangun bangunan!").exec();
}

void Bangun::execute(Walikota* walikota) {
    // ChoiceDialog dialog = ChoiceDialog(&window, {"Bangunan", "Tanaman"}, "Bangun", "Pilih jenis bangunan yang ingin dibangun", "pilih woi");
    // dialog.exec();

    string headerText = "Resep bangunan yang ada adalah sebagai berikut.";
    auto &recipeMap = state.getRecipeMap();
    QVector<QString> choices;
    vector<string> indexedKeys;
    
    int number = 1;
    for (auto &[key, building]: recipeMap) {
        string info = building->getFormattedBuildingInfo();
        choices.append(QString::fromStdString(to_string(number) + ". " + info));
        indexedKeys.push_back(key);
        number++;
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
            string message;
            message += "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

            if (missingMoney > 0) {
                message += to_string(missingMoney) + " gulden";
                if (!missingResources.empty()) {
                    message += ", serta ";
                }
            }

            for (auto &quantifiable: missingResources) {
                message += to_string(quantifiable.getQuantity()) + " " + formatName(quantifiable.getValue());
                if (&quantifiable != &missingResources.back()) {
                    message += ", ";
                } else {
                    message += ".";
                }
            }
            message += '\n';
            
            MessageBox(&window, "Bangun", message).exec();
            return;
        }

        // Build the building
        try{
            building->build(*walikota);
        } catch (exception &e) {
            MessageBox(&window, "Bangun", e.what()).exec();
            return;
        }

    });
    choiceDialog.exec();



}