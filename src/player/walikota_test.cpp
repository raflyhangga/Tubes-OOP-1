#include <gtest/gtest.h>
#include "tubesoop1/player/walikota.h"
using namespace std;

class WalikotaTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup if needed
    }

    void TearDown() override {
        // Clean-up code if needed 
        }
};

TEST_F(WalikotaTest,ConstructorTest){
    string username = "udin";
    Walikota temp(username);

    EXPECT_EQ(username,temp.getUsername());
}