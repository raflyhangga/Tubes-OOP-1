#include <gtest/gtest.h>
#include "tubesoop1/player/peternak.h"
using namespace std;

class PeternakTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup if needed
    }

    void TearDown() override {
        // Clean-up code if needed 
        }
};

TEST_F(PeternakTest,ConstructorTest){
    string username = "udin";
    Peternak temp(username);

    EXPECT_EQ(username,temp.getUsername());
}