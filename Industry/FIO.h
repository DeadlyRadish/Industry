#pragma once

#include <string>

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
};
