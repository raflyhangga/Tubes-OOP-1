#ifndef RESOURCE_TRANSLATOR_H
#define RESOURCE_TRANSLATOR_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/quantifiable/quantifiable.hpp"
#include "tubesoop1/player/player.h"
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/plant/plant.h"
#include "tubesoop1/creature/creature.h"
using namespace std;

/**
 * @brief Construct a Resource Creator for Resource Factory
 */
class ResourceCreator{
    public:
        Resource virtual Instantiate();
};

template <class T>
class Creator : public ResourceCreator{
    public:
        T virtual Instantiate() = 0;
};

#endif