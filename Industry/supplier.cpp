#include "supplier.h"

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
    if (input_balance > 0) {
        balance = input_balance;
        return true;
    }
    std::cout << "Невозможно записать отрицательное значение!" << std::endl;
    return false;
}


std::string Supplier::getName() {
    return name;
}
