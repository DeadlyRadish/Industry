#include "supplier.h"
#include <limits>

int Supplier::count = 0;

Supplier::Supplier() {
    name = FIO();
    balance = 0.0;
    date_of_delivery = Date();
    count++;
}

Supplier::~Supplier() {
    count--;
}

Supplier::Supplier(FIO input_name, double input_balance, Date input_date) {
    name = input_name;
    balance = input_balance;
    date_of_delivery = input_date;
    count++;
}

void Supplier::setName(std::string input_f_name, std::string input_s_name, std::string input_p_name) {
    name.setFirstName(input_f_name);
    name.setSecondName(input_s_name);
    name.setPatronymic(input_p_name);
}

void Supplier::setName(FIO input_name) {
    name = input_name;
}

bool Supplier::setBalance(double input_balance) {
    if (input_balance >= 0){
        balance = input_balance;
        return true;
    }
    return false;
}

bool Supplier::setDate(std::string input_date) {
    if (Date::isValidDate(input_date)) {
        date_of_delivery = input_date;
        return true;
    }
    return false;
}


std::string Supplier::getName()
{
    return name.getFirstName();
}

double Supplier::getBalance()
{
    return balance;
}

std::string Supplier::getDate()
{
    return date_of_delivery.formatDateAsString();
}

bool Supplier::operator==(const Supplier& other) {
    return balance == other.balance;
}

std::ostream& operator<<(std::ostream& os, const Supplier& firm) {
    os << firm.name
       << " / " << firm.balance
       << " / " << firm.date_of_delivery;
    return os;
}

std::istream& operator>>(std::istream& is, Supplier& supplier) {
    FIO name;
    Date date;
    double balance;

    std::cin >> name;

    if (!(is >> balance)) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Неверный формат для суммы поставки");
    }
    if (!supplier.setBalance(balance)) {
        throw std::runtime_error("Неверное значение для суммы поставки");
    }

    std::cin >> date;

    return is;
}

Supplier& Supplier::operator=(const Supplier& other) {
    if (this != &other) { // Prevent self-assignment
        name = other.name;
        balance = other.balance;
        date_of_delivery = other.date_of_delivery;
    }
    return *this;
}
