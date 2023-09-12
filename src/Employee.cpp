#include "Employee.h"

Employee::Employee() {}

Employee::Employee(const std::string& _name, const std::string& _phone, const std::string& _email, double _salary)
        : Person(_name, _phone, _email), _salary(_salary) {}

double Employee::salary() const {
    return _salary;
}

void Employee::salary(double _salary) {
    this->_salary = _salary;
}
