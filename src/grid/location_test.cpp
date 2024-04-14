#include "gtest/gtest.h"
#include "tubesoop1/grid/location.h"

// Test fixture for the Location class
class LocationTest : public ::testing::Test {
protected:
    // SetUp() is called before each test case
    void SetUp() override {
        // Create a default location object
        location = new Location(0, 0);
    }

    // TearDown() is called after each test case
    void TearDown() override {
        // Clean up memory
        delete location;
    }

    // Pointer to the Location object
    Location* location;
};

// Test case to verify row and column getters
TEST_F(LocationTest, Getters) {
    // Check if getters return the correct row and column
    EXPECT_EQ(location->getRow(), 0);
    EXPECT_EQ(location->getCol(), 0);
}

// Test case to verify equality operator
TEST_F(LocationTest, EqualityOperator) {
    // Create another location with same row and column
    Location* sameLocation = new Location(0, 0);

    // Check if equality operator returns true
    EXPECT_TRUE(*location == *sameLocation);

    // Clean up memory
    delete sameLocation;
}

// Additional test cases can be added as needed
