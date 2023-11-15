#include "../header/agriculture.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

// Calculate and return the percentage increase in sales for the AgriculturalProduct instance.
double AgriculturalProduct::calculate_sales_increase() const {
    return ((updated_sales - previous_sales) / static_cast<double>(previous_sales)) * 100;
}

// Implement other functions from AgricultureMarket and SupplierCustomerManagement here

// Default constructor for SupplierCustomerManagement, initializes reliability_score to 0.
SupplierCustomerManagement::SupplierCustomerManagement() : reliability_score(0) {}

// Parameterized constructor for SupplierCustomerManagement, setting attributes based on input.
SupplierCustomerManagement::SupplierCustomerManagement(const std::string& n, int score, const std::string& fb, const std::string& ct)
    : name(n), reliability_score(score), feedback(fb), contract(ct) {}

// Prompt the user to add product and market information to the AgricultureMarket instance.
void AgricultureMarket::add_product_and_market_information() {
    AgriculturalProduct product;

    // Input product details from the user.
    std::cout << "Enter product name: ";
    std::cin >> product.name;
    std::cout << "Enter previous price: ";
    std::cin >> product.previous_price;
    std::cout << "Enter previous sales: ";
    std::cin >> product.previous_sales;
    std::cout << "Enter updated price: ";
    std::cin >> product.updated_price;
    std::cout << "Enter updated sales: ";
    std::cin >> product.updated_sales;
    std::cout << "Is the product seasonal? (1 for yes, 0 for no): ";
    std::cin >> product.is_seasonal;
    std::cout << "Is the product organic? (1 for yes, 0 for no): ";
    std::cin >> product.is_organic;
    std::cout << "Does the product have GMO? (1 for yes, 0 for no): ";
    std::cin >> product.has_gmo;

    // Add the product to the products vector.
    products.push_back(product);
    std::cout << "Product and market information added successfully.\n";

    // Write product information to a file.
    std::ofstream file("agriculture.txt", std::ios::app);
    if (file.is_open()) {
        file << "Product Name: " << product.name << "\n";
        file << "Previous Price: " << product.previous_price << "\n";
        file << "Previous Sales: " << product.previous_sales << "\n";
        file << "Updated Price: " << product.updated_price << "\n";
        file << "Updated Sales: " << product.updated_sales << "\n";
        file << "Is Seasonal: " << product.is_seasonal << "\n";
        file << "Is Organic: " << product.is_organic << "\n";
        file << "Has GMO: " << product.has_gmo << "\n\n";
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing.\n";
    }
}


// Update the information of a product in the AgricultureMarket instance.
void AgricultureMarket::update_product() {
    std::cout << "Enter the product name to update information: ";
    std::string product_name;
    std::cin >> product_name;

    // Search for the product and update its information if found.
    for (auto& product : products) {
        if (product.name == product_name) {
            std::cout << "Enter updated price: ";
            std::cin >> product.updated_price;
            std::cout << "Enter updated sales: ";
            std::cin >> product.updated_sales;
            std::cout << "Is the product seasonal? (1 for yes, 0 for no): ";
            std::cin >> product.is_seasonal;
            std::cout << "Is the product organic? (1 for yes, 0 for no): ";
            std::cin >> product.is_organic;
            std::cout << "Does the product have GMO? (1 for yes, 0 for no): ";
            std::cin >> product.has_gmo;

            std::cout << "Product information updated successfully.\n";
            return;
        }
    }

    // Inform the user if the product is not found.
    std::cout << "Product not found.\n";
}

// Delete a product from the AgricultureMarket instance based on user input.
void AgricultureMarket::delete_product() {
    std::cout << "Enter the product name to delete: ";
    std::string product_name;
    std::cin >> product_name;

    // Use remove_if and erase to delete the product from the vector.
    auto it = std::remove_if(products.begin(), products.end(),
        [product_name](const AgriculturalProduct& product) {
            return product.name == product_name;
        });

    if (it != products.end()) {
        products.erase(it, products.end());
        std::cout << "Product deleted successfully.\n";
    }
    else {
        std::cout << "Product not found.\n";
    }
}

// List market information for a specific product based on user input.
void AgricultureMarket::list_market_information() const {
    std::cout << "Enter the product name to list market information: ";
    std::string product_name;
    std::cin >> product_name;
    std::stack<AgriculturalProduct> productStack;

    // Search for the product and push it onto the stack if found.
    for (const auto& product : products) {
        if (product.name == product_name) {
            productStack.push(product);
        }
    }

    // Display market information for the top product on the stack.
    if (!productStack.empty()) {
        AgriculturalProduct product = productStack.top();
        productStack.pop();

        std::cout << "Market information for " << product.name << ":\n";
        std::cout << "Previous Price: " << product.previous_price << "\n";
        std::cout << "Previous Sales: " << product.previous_sales << "\n";
        std::cout << "Updated Price: " << product.updated_price << "\n";
        std::cout << "Updated Sales: " << product.updated_sales << "\n";
        std::cout << "Sales Increase: " << product.calculate_sales_increase() << "%\n";
        std::cout << "Seasonal: " << (product.is_seasonal ? "Yes" : "No") << "\n";
        std::cout << "Organic: " << (product.is_organic ? "Yes" : "No") << "\n";
        std::cout << "GMO: " << (product.has_gmo ? "Yes" : "No") << "\n";
        return;
    }
    else {
        std::cout << "Product not found.\n";
        return;
    }
}

// List all products and their information in the AgricultureMarket instance.
void AgricultureMarket::list_products() const {
    std::cout << "List of Products:\n";
    // Read product information from a file.
    std::ifstream file("agriculture.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for reading.\n";
    }

    // Display information for each product in the vector.
    for (const auto& product : products) {
        std::cout << "Product Name: " << product.name << "\n";
        std::cout << "Previous Price: " << product.previous_price << "\n";
        std::cout << "Previous Sales: " << product.previous_sales << "\n";
        std::cout << "Updated Price: " << product.updated_price << "\n";
        std::cout << "Updated Sales: " << product.updated_sales << "\n";
        std::cout << "Sales Increase: " << product.calculate_sales_increase() << "%\n";
        std::cout << "Seasonal: " << (product.is_seasonal ? "Yes" : "No") << "\n";
        std::cout << "Organic: " << (product.is_organic ? "Yes" : "No") << "\n";
        std::cout << "GMO: " << (product.has_gmo ? "Yes" : "No") << "\n\n";
    }
}

// Add a new supplier or customer to the AgricultureMarket instance.
void AgricultureMarket::add_supplier_customer() {
    SupplierCustomerManagement scm;
    std::cout << "Enter name: ";
    std::cin >> scm.name;
    std::cout << "Enter reliability score: ";
    std::cin >> scm.reliability_score;
    std::cout << "Enter feedback: ";
    std::cin >> scm.feedback;
    std::cout << "Enter contract: ";
    std::cin >> scm.contract;

    // Add the new supplier/customer to the vector.
    suppliers_customers.push_back(scm);
    std::cout << "Supplier/Customer added successfully.\n";
}

// List all suppliers and customers in the AgricultureMarket instance.
void AgricultureMarket::list_suppliers_customers() const {
    std::cout << "List of Suppliers/Customers:\n";
    for (const auto& scm : suppliers_customers) {
        std::cout << "Name: " << scm.name << "\n";
        std::cout << "Reliability Score: " << scm.reliability_score << "\n";
        std::cout << "Feedback: " << scm.feedback << "\n";
        std::cout << "Contract: " << scm.contract << "\n\n";
    }
}

// List sales information for a specific product based on user input.
void AgricultureMarket::list_sales_information() const {
    std::cout << "Enter the product name to list sales information: ";
    std::string product_name;
    std::cin >> product_name;

    // Search for the product and display its sales information if found.
    for (const auto& product : products) {
        if (product.name == product_name) {
            std::cout << "Sales information for " << product.name << ":\n";
            std::cout << "Previous Price: " << product.previous_price << "\n";
            std::cout << "Previous Sales: " << product.previous_sales << "\n";
            std::cout << "Updated Price: " << product.updated_price << "\n";
            std::cout << "Updated Sales: " << product.updated_sales << "\n";
            std::cout << "Sales Increase: " << product.calculate_sales_increase() << "%\n";
            std::cout << "Seasonal: " << (product.is_seasonal ? "Yes" : "No") << "\n";
            std::cout << "Organic: " << (product.is_organic ? "Yes" : "No") << "\n";
            std::cout << "GMO: " << (product.has_gmo ? "Yes" : "No") << "\n";
            return;
        }
    }

    std::cout << "Product not found.\n";
}

// Display a menu for managing Agriculture and Agricultural Products Market and handle user choices.
void AgricultureMarket::list_menu() {
    while (true) {
        std::cout << "\nAgriculture and Agricultural Products Market Menu:\n";
        std::cout << "1. Add Supplier or Customer\n";
        std::cout << "2. Add Product\n";
        std::cout << "3. Update Product\n";
        std::cout << "4. Delete Products\n";
        std::cout << "5. List Products\n";
        std::cout << "6. Price and Demand Information\n";
        std::cout << "7. Suppliers and Customer Management\n";
        std::cout << "8. Exit\n";

        int choice;
        std::cout << "Enter your choice (1-8): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Call the function to add a new supplier or customer.
            add_supplier_customer();
            break;
        case 2:
            // Call the function to add product and market information.
            add_product_and_market_information();
            break;
        case 3:
            // Call the function to update product information.
            update_product();
            break;
        case 4:
            // Call the function to delete products.
            delete_product();
            break;
        case 5:
            // Call the function to list all products.
            list_products();
            break;
        case 6:
            // Call the function to list sales information for a specific product.
            list_sales_information();
            break;
        case 7:
            // Call the function to list suppliers and customers.
            list_suppliers_customers();
            break;
        case 8:
            // Display a message and exit the program.
            std::cout << "Exiting program.\n";
            return;
        default:
            // Inform the user of an invalid choice.
            std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }
    }
}