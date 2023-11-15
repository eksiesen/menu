#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

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

    double calculate_sales_increase() const;
};

class SupplierCustomerManagement {
public:
    std::string name;
    int reliability_score;
    std::string feedback;
    std::string contract;

    SupplierCustomerManagement();
    SupplierCustomerManagement(const std::string& n, int score, const std::string& fb, const std::string& ct);
};

class AgricultureMarket {
private:
    std::vector<AgriculturalProduct> products;
    std::vector<SupplierCustomerManagement> suppliers_customers;

public:
    void add_product_and_market_information();
    void update_product();
    void delete_product();
    void list_market_information() const;
    void list_products() const;
    void add_supplier_customer();
    void list_suppliers_customers() const;
    void list_sales_information() const;
    void list_menu();
};

// Declaration of the function defined in agriculture.cpp
extern double calculate_sales_increase(const AgriculturalProduct& product);
