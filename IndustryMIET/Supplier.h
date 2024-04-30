#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Date.h"
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
    Supplier(const Supplier& other): 
        name(other.name), 
        legal_address(other.legal_address), 
        balance(other.balance), 
        date_of_delivery(other.date_of_delivery)
    {
    }

    ~Supplier();
    friend std::ostream& operator<<(std::ostream& os, const Supplier& date);
    void setName(std::string);
    void setAddress(std::string);
    bool setBalance(double);
    bool setDate(std::string);
    bool operator==(const Supplier& other);

    std::string getName();
    std::string getAddress();
    double getBalance();
    std::string getDate();
};

#endif // SUPPLIER_H
