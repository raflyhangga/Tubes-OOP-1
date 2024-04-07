#include "tubesoop1/player/player.h"
#include <tubesoop1/grid/griddrawer.hpp>

int Player::moneyToWin;
int Player::weightToWin;

Player::Player(string &_username) : username(_username)
{
    weight = 0;
    money = 0;
}

void Player::putInventory(Resource &r)
{
    inventory.insert(&r);
}
void Player::putInventoryAt(Resource &r, Location &location)
{
    inventory.setElement(location, &r);
}

void Player::printInventory(){
    int total_length =inventory.getCol()*6 + 1;
    string message = " Penyimpanan ";
    string pad = string((total_length - message.length()) / 2 - 1, '=');
    cout << "   " <<  pad << '[' << message << ']' <<pad << endl;

    GridDrawerCLI<Resource*> drawer = GridDrawerCLI<Resource*>(inventory);
    drawer.draw();

    cout << "\nTotal slot kosong: " << inventory.getCountAvailable() << "\n\n";
}

string Player::getUsername()
{
    return username;
}
int Player::getMoney()
{
    return money;
}
int Player::getWeight()
{
    return weight;
}

Grid<Resource *>& Player::getInventory()
{
    return inventory;
}

bool Player::isWin()
{
    return weight >= weightToWin && money >= moneyToWin;
}

void Player::setMoney(int money)
{
    this->money = money;
}

void Player::removeInventory(Resource &r, int quantity) {
    if (quantity <= 0) {
        throw invalid_argument("Invalid quantity input");
    }

    vector<Location> locationsToRemove;
    Grid<Resource *> &playerInventory = getInventory();

    // Find all locations in the inventory that have the same resource as r
    int removedCount = 0;
    for (const auto &location : playerInventory.getAllAvaiable()) {
        Resource *res = playerInventory.getElement(location);
        if (res && *res == r) {
            locationsToRemove.push_back(location);
            removedCount++;
            if (removedCount >= quantity) {
                break; // Stop searching if desired quantity is reached
            }
        }
    }

    if (removedCount < quantity) {
        throw invalid_argument("Quantity resource yang di remove terlalu banyak");
    }

    // Delete the resources from the inventory
    for (const auto &location : locationsToRemove) {
        playerInventory.setElement(location, nullptr);
    }
}
Player::~Player() {
}
