#include <gtest/gtest.h>
#include "tubesoop1/something1/class1.hpp"

TEST(class1, add)
{
    class1 a;
    EXPECT_EQ(a.add(20, 30), 50);
    EXPECT_EQ(a.add(10, 30), 40);
    EXPECT_EQ(a.add(10, 20), 30);
    EXPECT_EQ(a.add(-5, 10), 5);
}
