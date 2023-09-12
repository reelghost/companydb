#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"
#include "Customer.h"
#include <vector>
#include <string>

class Company {
private:
    std::string _name;
    std::vector<Employee> _employees;
    std::vector<Customer> _customers;

public:
    Company(const std::string& _name);

    std::string name() const;
    void add_employee(const Employee& _employee);
    void add_customer(const Customer& _customer);

    void loadCompanyData();
    void saveCompanyData();

    using iterator = std::vector<Employee>::iterator;
    iterator employee_begin();
    iterator employee_end();

    using const_iterator = std::vector<Customer>::const_iterator;
    const_iterator customer_begin() const;
    const_iterator customer_end() const;

private:
    std::string getFileName() const; // Helper function to get the data file name
};

#endif // COMPANY_H
