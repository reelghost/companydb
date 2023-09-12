#include "Person.h"

Person::Person() {}

Person::Person(const std::string& _name, const std::string& _phone, const std::string& _email)
        : _name(_name), _phone(_phone), _email(_email) {}

std::string Person::name() const {
    return _name;
}

void Person::name(const std::string& _name) {
    this->_name = _name;
}

std::string Person::email() const {
    return _email;
}

void Person::email(const std::string& _email) {
    this->_email = _email;
}

std::string Person::phone() const {
    return _phone;
}

void Person::phone(const std::string& _phone) {
    this->_phone = _phone;
}
