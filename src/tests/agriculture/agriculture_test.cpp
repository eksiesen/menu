#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Agriculture.h" // Replace with the actual header file

class AgricultureMarketTest : public ::testing::Test {
protected:
    AgricultureMarket market;
};

TEST_F(AgricultureMarketTest, AddProductAndMarketInformation) {
    // Redirect cout to capture the output
    testing::internal::CaptureStdout();

    // Input sample data
    std::istringstream input("Product1\n10.0\n100\n12.0\n120\n1\n0\n0\n");
    std::cin.rdbuf(input.rdbuf());

    // Call the function
    market.add_product_and_market_information();

    // Reset cin
    std::cin.rdbuf(nullptr);

    // Get the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Assert statements for output
    ASSERT_TRUE(output.find("Product and market information added successfully.") != std::string::npos);
    ASSERT_TRUE(output.find("Product Name: Product1") != std::string::npos);
    ASSERT_TRUE(output.find("Previous Price: 10.0") != std::string::npos);
    // Add more assertions based on your expected output
}

// Add more test cases for other member functions

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
