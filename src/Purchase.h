#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>

class Purchase {
private:
    std::string _item;
    int _qty;
    double _cost;

public:
    Purchase(const std::string& _item, int _qty, double _cost);

    std::string item() const;
    int qty() const;
    double cost() const;
    double total() const;
};

#endif // PURCHASE_H
