#include "tubesoop1/player/player.h"

int Player::moneyToWin;
int Player::weightToWin;

Player::Player(string _username) : username(_username) {
    beratBadan = 0;
    uang = 0;
    inventory = Grid<Resource>(1, 1);
}


void Player::putInventory(Resource r){
    inventory.insert(r);

}
void Player::putInventoryAt(Resource r, Location location){
    inventory.setElement(location, r);
}

bool Player::isWin(){
    return beratBadan >= weightToWin && uang >= moneyToWin;
}