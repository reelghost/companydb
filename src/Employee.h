#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    double _salary;

public:
    Employee();
    Employee(const std::string& _name, const std::string& _phone, const std::string& _email, double _salary);

    double salary() const;
    void salary(double _salary);
};

#endif // EMPLOYEE_H
