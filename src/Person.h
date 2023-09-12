#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string _name;
    std::string _phone;
    std::string _email;
public:
    Person();
    Person(const std::string& _name, const std::string& _phone, const std::string& _email);

    std::string name() const;
    void name(const std::string& _name);

    std::string email() const;
    void email(const std::string& _email);

    std::string phone() const;
    void phone(const std::string& _phone);
};

#endif // PERSON_H
