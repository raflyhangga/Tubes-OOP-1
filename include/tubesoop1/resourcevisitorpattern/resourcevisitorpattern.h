#ifndef RESOURCE_VISITORPATTERN_H
#define RESOURCE_VISITORPATTERN_H

// Forward declaration to avoid circular dependency. Its normal for visitor pattern
class Resource;
class Animal;
class Plant;
class Product;
class ProductAnimal;
class ProductFruit;
class ProductMaterial;
class Building;

// Visitor pattern to avoid dynamic_cast
class TakerVisitor
{
    public:
        // Animal* take(Resource*);

        // Default will throw exception
        virtual void take(Animal*);
        virtual void take(Plant*);
        virtual void take(Product*);
        virtual void take(ProductAnimal*);
        virtual void take(ProductFruit*);
        virtual void take(ProductMaterial*);
        virtual void take(Building*);
};

// No need the Element because Resource is already the Element itself
// class TakenElement
// {
//     public:
//         virtual void taken(TakerVisitor &v) = 0;
// };

#endif