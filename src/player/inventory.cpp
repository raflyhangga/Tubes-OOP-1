#include "tubesoop1/player/inventory.h"

int Inventory::width;
int Inventory::height;

Inventory::Inventory() : Grid<Plant>(width, height){}
