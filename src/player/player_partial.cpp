#include "tubesoop1/player/player.h"
#include "tubesoop1/grid/location.h"
#include "tubesoop1/resourcevisitorpattern/taker.h"

// exist for the compiler 

template <class T>
inline T* Player::takeInventory(Location l)
{
    return Taker<T>().take(inventory[l])->get();
}
