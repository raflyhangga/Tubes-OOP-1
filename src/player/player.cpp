#include "tubesoop1/player/player.h"
#include <tubesoop1/grid/griddrawer.hpp>

int Player::moneyToWin;
int Player::weightToWin;

Player::Player(string &_username) : username(_username) {
    weight = 0;
    money = 0;
}


void Player::putInventory(Resource &r){
    inventory.insert(&r);

}
void Player::putInventoryAt(Resource &r, Location &location){
    inventory.setElement(location, &r);
}

void Player::printInventory(){
    GridDrawerCLI<Resource*> drawer = GridDrawerCLI<Resource*>(inventory);
    drawer.draw();
}

string Player::getUsername(){
    return username;
}
int Player::getMoney(){
    return money;
}
int Player::getWeight(){
    return weight;
}

bool Player::isWin(){
    return weight >= weightToWin && money >= moneyToWin;
}
