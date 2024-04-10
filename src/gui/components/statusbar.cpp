#include "tubesoop1/gui/components/statusbar.h"
#include "tubesoop1/player/player.h"

StatusBar::StatusBar() {
    setLayout(&vLayout);

    hLayout1.addWidget(&usernameLabel);
    hLayout1.addStretch();
    hLayout1.addWidget(&moneyLabel);

    hLayout2.addWidget(&typeLabel);
    hLayout2.addStretch();
    hLayout2.addWidget(&weightLabel);
    
    vLayout.addWidget(&widget1);
    vLayout.addWidget(&widget2);

    widget1.setLayout(&hLayout1);
    widget2.setLayout(&hLayout2);
}
void StatusBar::setPlayer(Player* player) {
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