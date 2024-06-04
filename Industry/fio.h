#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class FIO {
private:
    std::string firstName;
    std::string lastName;
    std::string patronymic;

public:
    void setFirstName(const std::string& first);
    std::string getFirstName() const;
    void setSecondName(const std::string& last);
    std::string getSecondName() const;
    void setPatronymic(const std::string& patr);
    std::string getPatronymic() const;

    friend std::istream& operator>>(std::istream& is, FIO& fio);
    friend std::ostream& operator<<(std::ostream& os, const FIO& fio);\

    FIO& operator=(const FIO& other);
    bool operator==(const FIO& other) const;
};
