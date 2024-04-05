#ifndef RESOURCE_TRANSLATOR_H
#define RESOURCE_TRANSLATOR_H

#include <map>
#include <string>
#include <fstream>
#include <functional>
#include "tubesoop1/resource/resource.h"
using namespace std;

/**
 * Translator to translate from string to Resource instance
*/
class ResourceTranslator : map<string, function<Resource()>>{
    public:

        /**
         * Load the content of the file in the configPath to the translator
        */
        ResourceTranslator(string configPath);

        /**
         * Translate the key to the Resource instance
        */
        Resource& translate(string key);
};

#endif