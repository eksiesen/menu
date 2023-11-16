#include "gtest/gtest.h"
#include "../header/agriculture.h"  // Include the header file for your classes


// Test cases for AgriculturalProduct class

TEST(AgriculturalProductTest, CalculateSalesIncrease) {
    AgriculturalProduct product;
    product.previous_sales = 100;
    product.updated_sales = 150;

    EXPECT_DOUBLE_EQ(product.calculate_sales_increase(), 50.0);
}

// Test cases for SupplierCustomerManagement class
TEST(SupplierCustomerManagementTest, DefaultConstructor) {
    SupplierCustomerManagement scm;

    
}

TEST(SupplierCustomerManagementTest, ParameterizedConstructor) {
    SupplierCustomerManagement scm("Supplier1", 80, "Good feedback", "ContractXYZ");

 
}

TEST(AgricultureMarketTest, DeleteProduct) {
    // Add a product first
    AgriculturalProduct product;
    product.name = "TestProduct";
    AgricultureMarket delete_product()

        // Simulate user input
        // ... (use std::istringstream to set up input)

        // Call the function


        // Check if the product was deleted    ASSERT_EQ(0, market.get_products().size());;
        ;
}

// Test cases for AgricultureMarket class
TEST(AgricultureMarketTest, AddProductAndMarketInformation) {
    AgricultureMarket market;

    // Redirect cout to capture the output
    testing::internal::CaptureStdout();

    // Provide input to simulate user input
    std::istringstream simulated_input("Product1\n100\n50\n120\n75\n1\n0\n1\n");
    std::cin.rdbuf(simulated_input.rdbuf());

    market.add_product_and_market_information();

    // Get the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the output contains the expected message
    EXPECT_TRUE(output.find("Product and market information added successfully.") != std::string::npos);
    // Add more assertions if needed.
}

        int main(int argc, char** argv) {
        
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
