#include "Customer.h"

Customer::Customer() {}

Customer::Customer(const std::string& _name, const std::string& _phone, const std::string& _email)
    : Person(_name, _phone, _email) {}

void Customer::add_purchase(const Purchase& purchase) {
    _history.push_back(purchase);
}

Customer::const_iterator Customer::purchase_begin() const {
    return _history.begin();
}

Customer::const_iterator Customer::purchase_end() const {
    return _history.end();
}

