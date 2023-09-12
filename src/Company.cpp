#include "Company.h"
#include <iostream>
#include <fstream>

Company::Company(const std::string& _name) : _name(_name) {}

std::string Company::name() const {
    return _name;
}

void Company::add_employee(const Employee& _employee) {
    _employees.push_back(_employee);
}

void Company::add_customer(const Customer& _customer) {
    _customers.push_back(_customer);
}

void Company::loadCompanyData() {
    std::string fileName = getFileName();

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Data file not found. Creating a new one.\n";
        return; // No data to load, return
    }

    // Implement loading company data from the file
    // Read the data and populate the _employees and _customers vectors

    file.close();
}

void Company::saveCompanyData() {
    std::string fileName = getFileName();

    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot create/open the data file.\n";
        return; // Cannot create/open the file, return
    }

    // Implement saving company data to the file
    // Write the data from _employees and _customers vectors to the file

    file.close();
}

std::string Company::getFileName() const {
    return _name + ".dat"; // Use the company name as the file name
}
