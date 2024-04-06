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
#include "tubesoop1/building/building.h"
using namespace std;

/**
 * Factory class for all Resource. It's like translator to translate from string to Resource instance
*/
class ResourceFactory : map<string, function<Resource*()>>{
    public:

        /**
         * Load the content of the file in the configPath to the translator
        */
        ResourceFactory(string configPath);

        ~ResourceFactory();

        /**
         * Translate the key to the Resource instance
        */
        Resource* translate(string key);

        friend ostream& operator<<(ostream& os, const ResourceFactory& factory);
};


#endif