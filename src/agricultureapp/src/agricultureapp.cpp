#include <iostream>
#include <vector>
#include <algorithm>

// The AgriculturalProduct class represents agricultural products.
class AgriculturalProduct {
public:
    std::string name;
    double previous_price;
    int previous_sales;
    double updated_price;
    int updated_sales;
    bool is_seasonal;
    bool is_organic;
    bool has_gmo;

    // Function to calculate the sales increase.
    double calculate_sales_increase() const {
        return ((updated_sales - previous_sales) / static_cast<double>(previous_sales)) * 100;
    }
};

//  The SupplierCustomerManagement class represents supplier and customer information.
class SupplierCustomerManagement {
public:
    std::string name;
    int reliability_score;
    std::string feedback;
    std::string contract;

    // Default constructor sets reliability_score to zero.
    SupplierCustomerManagement() : reliability_score(0) {}

    // Parameterized constructor creates an object with specified initial values.
    SupplierCustomerManagement(const std::string& n, int score, const std::string& fb, const std::string& ct)
        : name(n), reliability_score(score), feedback(fb), contract(ct) {}
};

// The AgricultureMarket class includes management of agricultural products and supplier/customer information.
class AgricultureMarket {
private:
    std::vector<AgriculturalProduct> products;
    std::vector<SupplierCustomerManagement> suppliers_customers;

public:
    // Function to add agricultural product and market information.
    void add_product_and_market_information() {
        AgriculturalProduct product;
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

        products.push_back(product);
        std::cout << "Product and market information added successfully.\n";
    }

    // Function to update information about a product.
    void update_product() {
        std::cout << "Enter the product name to update information: ";
        std::string product_name;
        std::cin >> product_name;

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

        std::cout << "Product not found.\n";
    }

    // Function to delete a product.
    void delete_product() {
        std::cout << "Enter the product name to delete: ";
        std::string product_name;
        std::cin >> product_name;

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

    // Function to list all products.
    void list_products() const {
        std::cout << "List of Products:\n";
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

    // Function to add a supplier or customer.
    void add_supplier_customer() {
        SupplierCustomerManagement scm;
        std::cout << "Enter name: ";
        std::cin >> scm.name;
        std::cout << "Enter reliability score: ";
        std::cin >> scm.reliability_score;
        std::cout << "Enter feedback: ";
        std::cin >> scm.feedback;
        std::cout << "Enter contract: ";
        std::cin >> scm.contract;

        suppliers_customers.push_back(scm);
        std::cout << "Supplier/Customer added successfully.\n";
    }

    // Function to list all suppliers and customers.
    void list_suppliers_customers() const {
        std::cout << "List of Suppliers/Customers:\n";
        for (const auto& scm : suppliers_customers) {
            std::cout << "Name: " << scm.name << "\n";
            std::cout << "Reliability Score: " << scm.reliability_score << "\n";
            std::cout << "Feedback: " << scm.feedback << "\n";
            std::cout << "Contract: " << scm.contract << "\n\n";
        }
    }
    // Function to list sales information for a specific product.
    void list_sales_information() const {
        std::cout << "Enter the product name to list sales information: ";
        std::string product_name;
        std::cin >> product_name;

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

    // Function to display the main menu and handle user input.
    void list_menu() {
        while (true) {


            std::cout << "****************************************************\n";
            std::cout << "* Agriculture and Agricultural Products Market Menu *\n";
            std::cout << "****************************************************\n\n\n";


            std::cout << "1. Add Supplier / Customer\n";
            std::cout << "2. Add Product\n";
            std::cout << "3. Update Product\n";
            std::cout << "4. Delete Product\n";
            std::cout << "5. List Products\n";
            std::cout << "6. Demand Informations\n";
            std::cout << "7. Supplier Management\n";
            std::cout << "8. Exit\n";

            int choice;
            std::cout << "Enter your choice (1-8): ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                add_supplier_customer();
                break;
            case 2:
                add_product_and_market_information();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                list_products();
                break;
            case 6:
                list_sales_information();
                break;
            case 7:
                list_suppliers_customers();
                break;
            case 8:
                std::cout << "Exiting program.\n";
                return;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 8.\n";
            }
        }
    }
};

// Main program
int main() {
    AgricultureMarket market;
    market.list_menu();

    return 0;
}
