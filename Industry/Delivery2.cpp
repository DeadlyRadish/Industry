#include "Delivery2.h"

int Supplier1::count = 0;

Supplier1::Supplier1() {
    seller = FIO();
    balance = 0.0;
    date_of_delivery = Date();
    count++;
}

Supplier1::~Supplier1() {
    count--;
}

Supplier1::Supplier1(FIO input_fio, double input_balance, Date input_date) {
    seller = input_fio;
    balance = input_balance;
    date_of_delivery = input_date;
    count++;
}

void Supplier1::setName(std::string input_first_name, std::string input_second_name, std::string input_patronymic) {
    seller.setFirstName(input_first_name);
    seller.setSecondName(input_second_name);
    seller.setPatronymic(input_patronymic);
}

bool Supplier1::setBalance(double input_balance){ 
    if (input_balance < 0) {
        return false;
    }
    else {
        balance = input_balance;
        return true;
    }
}

double Supplier1::getBalance() {
    return balance;
}

std::string Supplier1::getName()
{
    return seller.getFirstName() + " " + seller.getSecondName() + " " + seller.getPatronymic();
}

bool Supplier1::operator==(const Supplier1& other) {
    return balance == other.balance;
}

std::ostream& operator<<(std::ostream& os, const Supplier1& firm) {
    os << firm.seller.getFirstName() << " " << firm.seller.getSecondName() << " " << firm.seller.getPatronymic() << firm.balance << " " << firm.date_of_delivery;
    return os;
}