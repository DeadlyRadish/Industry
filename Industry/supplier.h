#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "date.h"
#include<iostream>
#include<string>

class Supplier
{
private:
    std::string name;
    std::string legal_address;
    double balance;
    Date date_of_delivery;
public:
    static int count;

    Supplier();
    Supplier(std::string, std::string, double, Date);

    ~Supplier();

    void setName(std::string);
    void setAddress(std::string);
    bool setBalance(double);
    bool setDate(Date);

    std::string getName();
    std::string getAddress();
    double getBalance();
    Date getDate();
};

#endif // SUPPLIER_H
