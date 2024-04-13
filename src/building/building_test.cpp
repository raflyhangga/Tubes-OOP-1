#include <gtest/gtest.h>
#include "tubesoop1/building/building.h"
#include "tubesoop1/product/product.h"
#include "tubesoop1/player/player.h"

TEST(BuildingTest, BuildingInitialization)
{
    vector<Quantifiable<ProductMaterial*>> recipe;
    Building temp("BDG", "Building", 100, recipe);

    EXPECT_EQ("BDG", temp.getCode());
    EXPECT_EQ("Building", temp.getName());
    EXPECT_EQ(100, temp.getPrice());
    EXPECT_EQ(0, temp.getRecipe().size());
}