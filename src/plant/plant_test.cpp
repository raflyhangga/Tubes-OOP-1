
#include <gtest/gtest.h>
#include <sstream>
#include "tubesoop1/plant/plant.h"
#include "tubesoop1/resource/creature.h" // Assuming this path and header file exist and are correct.

// Mock dependencies
// Assuming Creature and Product classes are defined properly in their headers.
// If not, please define mock classes here. For brevity, it's assumed they are defined.

class MockCreature : public Creature {
    // Mock implementation of Creature's methods if needed
};

class MockProduct : public Product {
    // Mock implementation of Product's methods if needed
};

TEST(PlantTest, ConstructorWithParameters) {
    vector<Product*> drops; // Assuming a proper implementation of Product
    Plant plant("P001", "Sunflower", 50, 10, drops);
    EXPECT_EQ(plant.getAge(), 0); // Assuming initial age is set to 0 in all constructors EXPECT_EQ(plant.isHarvestable(), false);
}

TEST(PlantTest, AgeManagement) {
    Plant plant;
    plant.setAge(5);
    EXPECT_EQ(plant.getAge(), 5);

    plant.addAge(3);
    EXPECT_EQ(plant.getAge(), 8);
}

TEST(PlantTest, Harvestability) {
    Plant plant("P001", "Sunflower", 50, 10, {});
    plant.setAge(5);
    EXPECT_FALSE(plant.isHarvestable());

    plant.setAge(10);
    EXPECT_TRUE(plant.isHarvestable());
}

TEST(PlantTest, EqualityOperator) {
    Plant plant1("P001", "Sunflower", 50, 10, {});
    Plant plant2("P001", "Sunflower", 50, 10, {});

    EXPECT_TRUE(plant1 == plant2);

    Plant plant3("P002", "Rose", 70, 5, {});
    EXPECT_FALSE(plant1 == plant3);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
