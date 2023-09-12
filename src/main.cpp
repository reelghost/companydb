#include "Company.h"
#include "Employee.h"
#include "Customer.h"
#include "Purchase.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>

// Function to load data from the company-specific data file
// Function to load data from the company-specific data file
// Function to load data from the company-specific data file
// Function to load data from the company-specific data file
void loadData(const std::string& companyName, std::vector<Employee>& employees, std::vector<Customer>& customers) {
    // Open the input file
    std::ifstream inFile("company_" + companyName + ".dat");
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file company_" << companyName << ".dat" << std::endl;
        return;
    }

    std::string line;
    std::string section; // To keep track of the current section (e.g., "Employees" or "Customers")

    while (std::getline(inFile, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        // Check if the line starts with '#' to identify sections
        if (line[0] == '#') {
            section = line.substr(2); // Extract the section name (e.g., "Company Name")
            continue;
        }

        // Split the line into fields using tabs as the separator
        std::istringstream iss(line);
        std::vector<std::string> fields;
        std::string field;
        while (std::getline(iss, field, '\t')) {
            fields.push_back(field);
        }

        // Process the data based on the current section
        if (section == "Employees") {
            if (fields.size() >= 4) {
                std::string name = fields[1];
                std::string phone = fields[3];
                std::string email = fields[5];
                double salary = std::stod(fields[7]);

                employees.push_back(Employee(name, phone, email, salary));
            }
        } else if (section == "Customers") {
            if (fields.size() >= 3) {
                std::string name = fields[1];
                std::string phone = fields[3];
                std::string email = fields[5];

                Customer newCustomer(name, phone, email);

                // Read purchase data for the customer
                while (std::getline(inFile, line)) {
                    if (line.empty() || line[0] == '#') {
                        break; // End of customer data or start of a new section
                    }

                    // Split the purchase data line into fields using tabs
                    std::istringstream purchaseIss(line);
                    std::vector<std::string> purchaseFields;
                    std::string purchaseField;
                    while (std::getline(purchaseIss, purchaseField, '\t')) {
                        purchaseFields.push_back(purchaseField);
                    }

                    if (purchaseFields.size() >= 3) {
                        std::string item = purchaseFields[1];
                        int qty = std::stoi(purchaseFields[3]);
                        double cost = std::stod(purchaseFields[5]);

                        Purchase purchase(item, qty, cost);
                        newCustomer.add_purchase(purchase);
                    }
                }

                customers.push_back(newCustomer);
            }
        }
    }

    inFile.close();
}







void saveData(const std::string& companyName, const std::vector<Employee>& employees, const std::vector<Customer>& customers) {
    // Open the output file
    std::ofstream outFile("company_" + companyName + ".dat", std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file company_" << companyName << ".dat" << std::endl;
        return;
    }

    // Write the header section
    outFile << "# Company Name\t" << companyName << "\n";
    outFile << "# Employees\n";

    // Write the employee data
    for (const Employee& emp : employees) {
        outFile << "Employee\t" << emp.name() << "\t";
        outFile << "Phone:\t" << emp.phone() << "\t";
        outFile << "Email:\t" << emp.email() << "\t";
        outFile << "Salary:\t" << emp.salary() << "\n";
    }

    outFile << "# Customers\n";

    // Write the customer data
    for (const Customer& cust : customers) {
        outFile << "Customer\t" << cust.name() << "\t";
        outFile << "Phone:\t" << cust.phone() << "\t";
        outFile << "Email:\t" << cust.email() << "\n";

        // Write purchase data for the customer
        for (Customer::const_iterator it = cust.purchase_begin(); it != cust.purchase_end(); ++it) {
            const Purchase& purchase = *it;
            outFile << "Purchase\t" << purchase.item() << "\t";
            outFile << "Quantity:\t" << purchase.qty() << "\t";
            outFile << "Cost:\t" << purchase.cost() << "\n";
        }

    }

    outFile.close();

    std::cout << "Data saved to company_" << companyName << ".dat" << std::endl;
}




int main() {
    std::string companyName;

    // Step 1: Prompt for the company name
    std::cout << "Enter the company name: ";
    std::getline(std::cin, companyName);

    // Step 2: Create a Company instance with the entered name
    Company myCompany(companyName);

    

    // Step 2: Create a Company instance and load data
    // Company myCompany(companyName);
    // myCompany.loadCompanyData();

    // Declare vectors to store employee and customer data
    std::vector<Employee> employees;
    std::vector<Customer> customers;

    // Step 3: Load existing data, if available
    loadData(companyName, employees, customers);

    // Step 3: Load existing data
    // loadData(companyName, employees, customers);

    // Step 4: Display the menu and handle user choices
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. View/Add Employees\n";
        std::cout << "2. View/Add Sales and Customers\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
            {
                // View/Add Employees
                std::cout << "1. View Employees\n";
                std::cout << "2. Add Employee\n";
                std::cout << "3. Go Back\n";
                std::cout << "Enter your choice: ";
                int empChoice;
                std::cin >> empChoice;

                switch (empChoice) {
                    case 1:
                        // View Employees
                        std::cout << "Employee List:\n";
                        for (const Employee& emp : employees) {
                            std::cout << "Name: " << emp.name() << " | Phone: " << emp.phone()
                                      << " | Email: " << emp.email() << " | Salary: " << emp.salary() << std::endl;
                        }
                        break;
                    case 2:
                    {
                        // Add Employee
                        std::string name, phone, email;
                        double salary;

                        std::cout << "Enter employee name: ";
                        std::cin.ignore();
                        std::getline(std::cin, name);

                        std::cout << "Enter employee phone: ";
                        std::cin >> phone;

                        std::cout << "Enter employee email: ";
                        std::cin >> email;

                        std::cout << "Enter employee salary: ";
                        std::cin >> salary;

                        // Create a new Employee object and add it to the vector
                        Employee newEmployee(name, phone, email, salary);
                        employees.push_back(newEmployee);

                        saveData(companyName, employees, customers);

                        std::cout << "Employee added successfully.\n";
                        break;
                    }
                    case 3:
                        // Go back to the main menu
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                        break;
                }
                break;
            }
            case 2:
            {
                // View/Add Sales and Customers
                std::cout << "1. View Sales\n";
                std::cout << "2. Add Customer\n";
                std::cout << "3. Go Back\n";
                std::cout << "Enter your choice: ";
                int salesChoice;
                std::cin >> salesChoice;

                switch (salesChoice) {
                    case 1:
                    {
                        // View Sales
            std::cout << "Sales History:\n";
            for (const Customer& cust : customers) {
                std::cout << "Customer: " << cust.name() << std::endl;
                for (Customer::const_iterator it = cust.purchase_begin(); it != cust.purchase_end(); ++it) {
                    const Purchase& purchase = *it;
                    std::cout << "Item: " << purchase.item() << " | Quantity: " << purchase.qty() << " | Cost: " << purchase.cost() << " | Total: " << purchase.total() << std::endl;
                }
                std::cout << "---------------------------------------------\n";
            }
            break;
                    }
                    case 2:
                    {
                        // Add Customer
                        std::string custName, custPhone, custEmail;

                        std::cout << "Enter customer name: ";
                        std::cin.ignore();
                        std::getline(std::cin, custName);

                        std::cout << "Enter customer phone: ";
                        std::cin >> custPhone;

                        std::cout << "Enter customer email: ";
                        std::cin >> custEmail;

                        // Create a new Customer object
                        Customer newCustomer(custName, custPhone, custEmail);

                        // Add purchases for the customer
                        while (true) {
                            std::string item;
                            int qty;
                            double cost;

                            std::cout << "Enter purchased item (or type 'done' to finish adding purchases): ";
                            std::cin.ignore();
                            std::getline(std::cin, item);

                            if (item == "done") {
                                break; // Exit the loop when 'done' is entered
                            }

                            std::cout << "Enter quantity: ";
                            std::cin >> qty;

                            std::cout << "Enter cost per item: ";
                            std::cin >> cost;

                            // Create a new Purchase object
                            Purchase purchase(item, qty, cost);

                            // Add the purchase to the customer's history
                            newCustomer.add_purchase(purchase);
                        }

                        // Add the customer to the vector
                        customers.push_back(newCustomer);

                        saveData(companyName, employees, customers);

                        std::cout << "Customer added successfully.\n";
                        break;
                    }
                    case 3:
                        // Go back to the main menu
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                        break;
                }
                break;
            }
            case 3:
                // Exit the program and save all data
                // Save data
                saveData(companyName, employees, customers);

                // Save company data (if needed)
                myCompany.saveCompanyData();

                std::cout << "Exiting the program. Data saved successfully.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 3);

    // Step 5: Save data before exiting
    saveData(companyName, employees, customers);
    myCompany.saveCompanyData();

    return 0;
}
