#include "tubesoop1/player/player.h"
#include <tubesoop1/grid/griddrawer.hpp>
#include "tubesoop1/product/product.h"

int Player::moneyToWin;
int Player::weightToWin;

Player::Player(string &_username) : username(_username)
{
    weight = 40;
    money = 50;
}

void Player::putInventory(Resource &r)
{
    inventory.insert(&r);
}
void Player::putInventoryAt(Resource &r, Location &location)
{
    inventory.setElement(location, &r);
}
Grid<Resource*> &Player::getInventory() {
    return inventory;
}

string Player::getUsername(){
    return username;
}
void Player::setWeight(int weight){
    this->weight = weight;
}
void Player::setMoney(int money){
    this->money = money;
}
void Player::addMoney(int money){
    this->money += money;
}
int Player::getMoney()
{
    return money;
}
int Player::getWeight()
{
    return weight;
}

bool Player::isWin()
{
    return weight >= weightToWin && money >= moneyToWin;
}


void Player::removeInventory(Resource &r, int quantity) {
    if (quantity <= 0) {
        throw invalid_argument("Invalid quantity input");
    }

    vector<Location> locationsToRemove;
    Grid<Resource *> &playerInventory = getInventory();

    // Find all locations in the inventory that have the same resource as r
    int removedCount = 0;
    for (const auto &location : playerInventory.getAllFilled()) {
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
        playerInventory.pop(location);
    }
}

void Player::removeInvetoryAt(Location &location){
    inventory.pop(location);
}
Player::~Player() {
}

int Player::getNetWealth(){
    int totalMoney = 0;
    for(Location l : inventory){
        totalMoney += inventory[l]->getPrice();
    }
    return totalMoney;
}
int Player::getKKP(){
    return getNetWealth() - getKTKP();
}
int Player::getKKPRate(){
    int kkp = getKKP();
    if(kkp <= 6) return 5;
    else if(kkp <= 25) return 15;
    else if(kkp <= 50) return 25;
    else if(kkp <= 500) return 30;
    else return 35;
}
int Player::calculateTax(){
    int tax = (float)getKKPRate()/100.0 * getKKP();
    return tax;
}

void Player::eat(Product &p){
    weight += p.getAddedWeight();

}