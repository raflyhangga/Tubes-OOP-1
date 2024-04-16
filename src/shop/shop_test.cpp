#include <gtest/gtest.h>
#include "tubesoop1/quantifiable/quantifiable.hpp"
#include "tubesoop1/player/player.h"
#include "tubesoop1/resource/resource.h"
#include "tubesoop1/shop/shop_exception.h"
#include "tubesoop1/shop/shop.h"
#include "tubesoop1/resourcevisitorpattern/taker.hpp"


// // Mock Resource class for testing
// class MockResource : public Resource {
// public:
//     MockResource(const std::string& code, const std::string& name, int price)
//         : Resource(code, name, price) {}
// };

// TEST(ShopTest, ShopInitialization)
// {
//     // Initialize Shop with empty stock
//     Shop shop;

//     // Test if the stock is empty
//     EXPECT_TRUE(shop.getstock().empty());
// }

// class MockResource : public Resource {
// public:
//     MockResource(const std::string& code, const std::string& name, int price)
//         : Resource(code, name, price) {}
// };

TEST(ShopTest, ShopInitialization)
{
    // Initialize Shop with empty stock
    Shop shop;

    // Test if the stock is empty
    EXPECT_TRUE(shop.getstock().empty());
}

