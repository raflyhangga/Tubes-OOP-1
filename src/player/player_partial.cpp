#include "tubesoop1/player/player.h"
#include "tubesoop1/grid/location.h"
#include "tubesoop1/resourcevisitorpattern/taker.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern_exception.h"
#include <tubesoop1/cli/command/command_exception.h>

// exist for the compiler 

template <class T>
inline T* Player::takeInventory(Location l)
{
    return Taker<T>().take(inventory[l])->get();
}

template <class T>
inline vector<T*> Player::takeAllFromInventory()
{
    Taker<T> taker;
    vector<T*> v;
    for(const auto &l : inventory){
        Resource* r = inventory[l];
        try{
            v.push_back(taker.take(r)->get());
        } catch(NotTakableException &e) {
        } catch(exception &e) {
        }
    }

    if (v.size() == 0) throw EmptyInventoryException();

    return v;
}
