#include <gtest/gtest.h>
#include "tubesoop1/animal/animal.h"
#include "tubesoop1/animal/herbivore.h"
#include "tubesoop1/animal/omnivore.h"
#include "tubesoop1/animal/carnivore.h"

TEST(AnimalTest, AnimalInitiation)
{
    vector<Product*> emptyDrops;
    Herbivore tempH("HRB","HERBIVORE",5,10,emptyDrops);
    Omnivore tempO("OMN","OMNIVORE",2,12,emptyDrops);
    Carnivore tempC("CRN","CARNIVORE",3,30,emptyDrops);

    EXPECT_EQ("HRB", tempH.getCode());
    EXPECT_EQ("HERBIVORE", tempH.getName());
    EXPECT_EQ(5, tempH.getPrice());
    EXPECT_EQ(10, tempH.getWeightToHarvest());

    EXPECT_EQ("OMN", tempO.getCode());
    EXPECT_EQ("OMNIVORE", tempO.getName());
    EXPECT_EQ(2, tempO.getPrice());
    EXPECT_EQ(12, tempO.getWeightToHarvest());

    EXPECT_EQ("CRN", tempC.getCode());
    EXPECT_EQ("CARNIVORE", tempC.getName());
    EXPECT_EQ(3, tempC.getPrice());
    EXPECT_EQ(30, tempC.getWeightToHarvest());
}

TEST(AnimalTest, AnimalWeightManipulation)
{
    vector<Product*> emptyDrops;
    Herbivore tempH("HRB","HERBIVORE",5,10,emptyDrops);
    Omnivore tempO("OMN","OMNIVORE",2,12,emptyDrops);
    Carnivore tempC("CRN","CARNIVORE",3,30,emptyDrops);
    tempH.setWeight(100);
    tempO.setWeight(100);
    tempC.setWeight(100);

    EXPECT_EQ(100, tempH.getWeight());
    EXPECT_EQ(100, tempC.getWeight());
    EXPECT_EQ(100, tempO.getWeight());
}

TEST(AnimalTest, AnimalHarvestability)
{
    vector<Product*> drops;
    Herbivore temp("ANM", "Animal", 10, 50, drops);

    // By default, weight is 0, so it should not be harvestable
    EXPECT_FALSE(temp.isHarvestable());

    // Setting weight to be equal to weightToHarvest, it should be harvestable
    temp.setWeight(50);

    EXPECT_TRUE(temp.isHarvestable());
}