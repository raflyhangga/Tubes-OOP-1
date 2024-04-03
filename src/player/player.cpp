#include "tubesoop1/player/player.h"

Player::Player(string username, int beratBadan, int uang) {
    username = username;
    beratBadan = beratBadan;
    uang = uang;
}


Player::Player() {
    username = "";
    beratBadan = 0;
    uang = 0;
}