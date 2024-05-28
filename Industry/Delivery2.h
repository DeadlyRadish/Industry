#pragma once

#include "Date.h"
#include "FIO.h"
#include "Common.h"
#include<iostream>
#include<string>

class Supplier1: public Common
{
private:
    double balance;
    Date date_of_delivery;

public:
    FIO seller;
    static int count;

    Supplier1();
    Supplier1(FIO, double, Date);
    Supplier1(const Supplier1& other) :
        seller(other.seller),
        balance(other.balance),
        date_of_delivery(other.date_of_delivery)
    {
    }

    ~Supplier1();
    friend std::ostream& operator<<(std::ostream& os, const Supplier1& date);
    void setName(std::string, std::string, std::string);
    bool setBalance(double);
 
    bool operator==(const Supplier1& other);

    std::string getName();
    double getBalance();
};