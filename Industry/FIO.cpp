#include "FIO.h"

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