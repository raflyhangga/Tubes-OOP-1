#include <gtest/gtest.h>
#include <tubesoop1/quantifiable/quantifiable.hpp>

// Mock resource for testing
class MockResource {
public:
    MockResource(int val) : value(val) {}
    int getValue() const { return value; }

private:
    int value;
};

TEST(QuantifiableTest, Initialization)
{
    // Initialize Quantifiable object with positive quantity
    MockResource resource(10);
    Quantifiable<MockResource> quantifiable(resource, 5);

    // Test if the value and quantity are initialized correctly
    EXPECT_EQ(10, quantifiable.getValue().getValue());
    EXPECT_EQ(5, quantifiable.getQuantity());
}

TEST(QuantifiableTest, QuantityIncrement)
{
    // Initialize Quantifiable object
    MockResource resource(10);
    Quantifiable<MockResource> quantifiable(resource, 5);

    // Increment quantity by 1
    quantifiable += 1;

    // Test if the quantity is incremented correctly
    EXPECT_EQ(6, quantifiable.getQuantity());
}

TEST(QuantifiableTest, QuantityDecrement)
{
    // Initialize Quantifiable object
    MockResource resource(10);
    Quantifiable<MockResource> quantifiable(resource, 5);

    // Decrement quantity by 1
    quantifiable -= 1;

    // Test if the quantity is decremented correctly
    EXPECT_EQ(4, quantifiable.getQuantity());
}

// Add more tests as needed
