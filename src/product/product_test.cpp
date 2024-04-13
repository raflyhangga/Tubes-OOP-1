#include <gtest/gtest.h>
#include "tubesoop1/product/product.h"
// #include "productvisitorpattern.h"
#include "tubesoop1/animal/animal_exception.h"

// Mock EaterVisitor for testing
class MockEaterVisitor : public EaterVisitor {
public:
    void eat(ProductAnimal& animal) override {
        // Mock implementation
    }

    void eat(ProductFruit& fruit) override {
        // Mock implementation
    }

    void eat(ProductMaterial& material) override {
        // Mock implementation
    }
};

TEST(ProductTest, ProductAnimalInitialization)
{
    // Test ProductAnimal initialization
    ProductAnimal animal("ANM", "Animal", 20, 80);

    EXPECT_EQ("ANM", animal.getCode());
    EXPECT_EQ("Animal", animal.getName());
    EXPECT_EQ(20, animal.getAddedWeight());
    EXPECT_EQ(80, animal.getPrice());
}

TEST(ProductTest, ProductFruitInitialization)
{
    // Test ProductFruit initialization
    ProductFruit fruit("FRU", "Fruit", 10, 30);

    EXPECT_EQ("FRU", fruit.getCode());
    EXPECT_EQ("Fruit", fruit.getName());
    EXPECT_EQ(10, fruit.getAddedWeight());
    EXPECT_EQ(30, fruit.getPrice());
}

TEST(ProductTest, ProductMaterialInitialization)
{
    // Test ProductMaterial initialization
    ProductMaterial material("MTL", "Material", 15, 50);

    EXPECT_EQ("MTL", material.getCode());
    EXPECT_EQ("Material", material.getName());
    EXPECT_EQ(15, material.getAddedWeight());
    EXPECT_EQ(50, material.getPrice());
}

// Add more tests as needed
