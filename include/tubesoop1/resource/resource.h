#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/resourcevisitorpattern/resourcevisitorpattern.h"
using namespace std;

/**
 * Suatu abstract class untuk semua item yang bisa disimpan dalam
 * suatu inventory
 */

class Resource
{
protected:
    string code;
    string name;
    int price;

public:
   Resource() = default;
    virtual ~Resource();
    Resource(string code, string name, int price);

    /**
     * @brief Mengembalikan code dari resource
     * 
     * @return string code dari resource
     */
    string getCode() const;
    /**
     * @brief Mengembalikan nama dari resource
     * 
     * @return string nama dari resource
     */
    string getName() const;

    /**
     * @brief Mengembalikan harga dari resource
     * 
     * @return int harga dari resource
     */
    int getPrice() const;

    bool operator==(Resource&);

    friend ostream &operator<<(ostream &os, const Resource &res);

    // visitor pattern
    virtual void taken(TakerVisitor*) = 0;
};

#endif
