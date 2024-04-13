#include <tubesoop1/cli/command/status.h>
#include <iostream>

using namespace std;
Status::Status(State &state) : Command(state) {}

void Status::execute(Peternak *player) {
    cout << "Nama:  " << player->getUsername() << endl;
    cout << "Role:  Peternak" << endl;
    cout << "Uang:  " << player->getMoney() << endl;
    cout << "Berat: " << player->getWeight() << endl;
    cout << "=============== [Winning Condition] ==================" << endl;
    cout << "Berat untuk menang: " << Player::weightToWin << endl;
    cout << "Uang untuk menang: " << Player::moneyToWin << endl;
    cout << "======================================================" << endl;
}

void Status::execute(Petani *player) {
    cout << "Nama:  " << player->getUsername() << endl;
    cout << "Role:  Petani" << endl;
    cout << "Uang:  " << player->getMoney() << endl;
    cout << "Berat: " << player->getWeight() << endl;
    cout << "=============== [Winning Condition] ==================" << endl;
    cout << "Berat untuk menang: " << Player::weightToWin << endl;
    cout << "Uang untuk menang: " << Player::moneyToWin << endl;
    cout << "======================================================" << endl;
}

void Status::execute(Walikota *player) {
    cout << "================== [Player Info] =====================" << endl;
    cout << "Nama:  " << player->getUsername() << endl;
    cout << "Role:  Walikota" << endl;
    cout << "Uang:  " << player->getMoney() << endl;
    cout << "Berat: " << player->getWeight() << endl;
    cout << "=============== [Winning Condition] ==================" << endl;
    cout << "Berat untuk menang: " << Player::weightToWin << endl;
    cout << "Uang untuk menang: " << Player::moneyToWin << endl;
    cout << "======================================================" << endl;
}

