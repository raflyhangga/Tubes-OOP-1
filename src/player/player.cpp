#include "tubesoop1/player/player.h"

Player::Player(string username, int beratBadan, int uang) {
    username = username;
    beratBadan = beratBadan;
    uang = uang;
}


Player::Player(string _username) : username(_username) {
    beratBadan = 0;
    uang = 0;
    inventory = Grid<Resource>(1, 1);
}


void Player::putInventory(Resource r){
    // inventory.put(r);
}
void Player::putInventoryAt(Resource r, Location location){
    // inventory.put(r, location);
}