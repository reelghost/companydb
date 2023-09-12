#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Purchase.h"
#include <vector>

class Customer : public Person {
private:
    std::vector<Purchase> _history;

public:
    Customer();
    Customer(const std::string& _name, const std::string& _phone, const std::string& _email);

    void add_purchase(const Purchase& purchase);

    using const_iterator = std::vector<Purchase>::const_iterator;
    const_iterator purchase_begin() const;
    const_iterator purchase_end() const;
};

#endif // CUSTOMER_H
