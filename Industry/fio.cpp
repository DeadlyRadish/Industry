#include "fio.h"

void FIO::setFirstName(const std::string& first) {
    firstName = first;
}
std::string FIO::getFirstName() const{
    return firstName;
}
void FIO::setSecondName(const std::string& last) {
    lastName = last;
}
std::string FIO::getSecondName() const {
    return lastName;
}
void FIO::setPatronymic(const std::string& patr) {
    patronymic = patr;
}
std::string FIO::getPatronymic() const {
    return patronymic;
}

std::istream& operator>>(std::istream& is, FIO& fio) {
    std::string first, last, patr;

    std::cout << "Введите имя поставщика: ";
    std::getline(is >> std::ws, first);
    std::cout << "Введите фамилию поставщика: ";
    std::getline(is >> std::ws, last);
    std::cout << "Введите отчество поставщика: ";
    std::getline(is >> std::ws, patr);

    fio.setFirstName(first);
    fio.setSecondName(last);
    fio.setPatronymic(patr);

    return is;
}

std::ostream& operator<<(std::ostream& os, const FIO& fio) {
    os << fio.getFirstName() << " " << fio.getSecondName() << " " << fio.getPatronymic();
    return os;
}

FIO& FIO::operator=(const FIO& other) {
    if (this != &other) { // Prevent self-assignment
        firstName = other.firstName;
        lastName = other.lastName;
        patronymic = other.patronymic;
    }
    return *this;
}

bool FIO::operator==(const FIO& other) const {
    return (firstName == other.firstName && lastName == other.lastName && patronymic == other.patronymic);
}
