#include "tubesoop1/gui/components/statusbar.h"
#include "tubesoop1/player/player.h"

StatusBar::StatusBar(Player* player) {
    setLayout(&vLayout);

    vLayout.addWidget(&usernameLabel);
    vLayout.addWidget(&typeLabel);
    vLayout.addWidget(&moneyLabel);
    vLayout.addWidget(&weightLabel);    

    this->player = player;
    refresh();
}
void StatusBar::refresh() {
    const char* className = getClassName(*player);
    usernameLabel.setText(QString::fromStdString("Username: " + player->getUsername()));
    typeLabel.setText(QString::fromStdString("Role: " + string(className)));
    moneyLabel.setText(QString::fromStdString("Money: " + to_string(player->getMoney())));
    weightLabel.setText(QString::fromStdString("Weight: " + to_string(player->getWeight())));
}

const char* StatusBar::getClassName(Player &player){
    const type_info& typeInfo = typeid(player);
    const char* typeName = typeInfo.name();
    const char* mangledName = typeInfo.name();
    int prefixLength = 0;
    while (std::isdigit(mangledName[prefixLength])) {
        prefixLength++;
    }
    const char* className = mangledName + prefixLength;
    return className;
}