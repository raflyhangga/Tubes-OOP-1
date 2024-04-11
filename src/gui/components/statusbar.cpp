#include "tubesoop1/gui/components/statusbar.h"
#include "tubesoop1/player/player.h"

StatusBar::StatusBar() {
    setLayout(&hLayout);

    hLayout.addWidget(&widget1);
    hLayout.addStretch();
    hLayout.addWidget(&widget2);
    
    widget1.setLayout(&vLayout1);
    widget2.setLayout(&vLayout2);

    vLayout1.addWidget(&usernameLabel);
    vLayout1.addWidget(&typeLabel);
    vLayout1.addStretch();

    vLayout2.addWidget(&moneyLabel);
    vLayout2.addWidget(&weightLabel);
    vLayout2.addWidget(&moneyToWinLabel);
    vLayout2.addWidget(&weightToWinLabel);
    vLayout2.addStretch();
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
    moneyToWinLabel.setText(QString::fromStdString("Money To Win: " + to_string(Player::moneyToWin)));
    weightToWinLabel.setText(QString::fromStdString("Weight To Win: " + to_string(Player::weightToWin)));
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