#include <gtest/gtest.h>
#include "tubesoop1/something2/class2.hpp"

TEST(class2, multiply)
{
    class2 a;
    EXPECT_EQ(a.multiply(2, 3), 6);
    EXPECT_EQ(a.multiply(5, 3), 15);
    EXPECT_EQ(a.multiply(20, 30), 600);
}
