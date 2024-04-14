#include "tubesoop1/grid/grid.hpp"
#include <gtest/gtest.h>

class Item {
private:
    std::string name;
    int value;

public:
    Item(const std::string& name, int value) : name(name), value(value) {}

    const std::string& getName() const { return name; }
    int getValue() const { return value; }
};

// Test fixture for the Grid class
class GridTest : public ::testing::Test {
protected:
    // SetUp() is called before each test case
    void SetUp() override {
        // Create a 3x3 grid of Item pointers
        grid = new Grid<Item*>(3, 3);
    }

    // TearDown() is called after each test case
    void TearDown() override {
        // Clean up memory
        delete grid;
    }

    // Pointer to the Grid object
    Grid<Item*>* grid;
};

// Test case to verify grid initialization
TEST_F(GridTest, Initialization) {
    // Check if grid has the correct dimensions
    EXPECT_EQ(grid->getRow(), 3);
    EXPECT_EQ(grid->getCol(), 3);

    // Check if the grid is initially empty
    EXPECT_EQ(grid->getCountFilled(), 0);
    EXPECT_EQ(grid->getCountNotFilled(), 9);
}

// Test case to verify element insertion and retrieval
TEST_F(GridTest, InsertionAndRetrieval) {
    // Create an Item object
    Item* item = new Item("Sword", 100);

    // Insert the item into the grid at location (0, 0)
    grid->setElement(Location(0, 0), item);

    // Check if the item was inserted correctly
    EXPECT_EQ(grid->getCountFilled(), 1);
    EXPECT_EQ(grid->getCountNotFilled(), 8);
    EXPECT_EQ(grid->getElement(Location(0, 0)), item);

    // Clean up memory
    delete item;
}