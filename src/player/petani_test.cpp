
#include <gtest/gtest.h>
#include "tubesoop1/player/petani.h"
#include "tubesoop1/plant/plant.h"
#include "tubesoop1/grid/location.h"
#include "tubesoop1/player/walikota.h"
#include "tubesoop1/player/taxreport.h"

class MockPlant : public Plant {
public:
    vector<Product*> drops;
    MockPlant(int price, bool harvestable) : Plant("","", price, 0,drops), _harvestable(harvestable) {}

    bool isHarvestable() const override {
        return _harvestable;
    }

    void addAge(int age) {
        // Mock implementation 
    }

private:
    bool _harvestable;
};

class PetaniTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup if needed
    }

    void TearDown() override {
        // Clean-up code if needed 
        }
};

TEST_F(PetaniTest, ConstructorTest) {
    std::string username = "FarmerJoe";
    Petani petani(username);

    ASSERT_EQ(petani.getUsername(), username);
}


TEST_F(PetaniTest, BayarPajak) {
    std::string usernameP = "FarmerJoe";
    std::string usernameW = "WalikotaJoe";
    Petani petani(usernameP);
    Walikota walikota(usernameW);

    auto taxReport = petani.bayarPajak(walikota);
    ASSERT_NE(taxReport, nullptr);
    ASSERT_EQ(taxReport->getName(), usernameP);
    ASSERT_EQ(taxReport->getRole(), "Petani");
    delete taxReport;
} 
