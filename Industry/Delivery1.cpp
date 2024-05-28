#include "Delivery1.h"

int Supplier::count = 0;

Supplier::Supplier() {
    name = "Unknow";
    legal_address = "Unknow";
    balance = 0.0;
    date_of_delivery = Date();
    count++;
}

Supplier::~Supplier() {
    count--;
}

Supplier::Supplier(std::string input_name, std::string input_address, double input_balance, Date input_date) {
    name = input_name;
    legal_address = input_address;
    balance = input_balance;
    date_of_delivery = input_date;
    count++;
}

void Supplier::setName(std::string input_name) {
    name = input_name;
}

bool Supplier::setBalance(double input_balance) {
    balance = input_balance;
    return true;
}

void Supplier::setAddress(std::string input_address) {
    legal_address = input_address;
}


std::string Supplier::getName()
{
    return name;
}

std::string Supplier::getAddress()
{
    return legal_address;
}

double Supplier::getBalance()
{
    return balance;
}

bool Supplier::operator==(const Supplier& other) {
    return balance == other.balance;
}

std::ostream& operator<<(std::ostream& os, const Supplier& firm) {
    os << firm.name << " " << firm.legal_address << " " << firm.balance << " " << firm.date_of_delivery;
    return os;
}
