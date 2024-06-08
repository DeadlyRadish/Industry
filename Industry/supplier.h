#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "date.h"
#include "fio.h"
#include<iostream>
#include<string>

class Supplier
{
private:
    double balance;
    Date date_of_delivery;

public:
    FIO name;
    static int count;

    Supplier();
    Supplier(FIO, double, Date);
    Supplier(const Supplier& other):
        name(other.name),
        balance(other.balance),
        date_of_delivery(other.date_of_delivery)
    {
    }

    ~Supplier();
    friend std::ostream& operator<<(std::ostream& os, const Supplier& date);
    void setName(std::string, std::string, std::string);
    void setName(FIO);
    bool setBalance(double);
    bool setDate(std::string);
    bool operator==(const Supplier& other);
    Supplier& operator=(const Supplier& other);

    std::string getName();
    double getBalance();
    std::string getDate();

    friend std::istream& operator>>(std::istream& is, Supplier& supplier);
};

#endif // SUPPLIER_H
