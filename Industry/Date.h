#pragma once

#include <iostream>
#include <sstream>

class Date {
private:
    int day;
    int month;
    int year;

    static bool isLeapYear(int year);
    int daysInMonth(int month, int year);

public:
    Date() {};
    Date(int d, int m, int y);
    void incrementDay();
    std::string formatDateAsString();

    Date operator++(int);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    bool operator<(const Date& other);
    bool operator>(const Date& other);
    bool operator==(const Date& other);
    bool operator!=(const Date& other);
    Date& operator=(const std::string& dateStr);
    static bool isValidDate(const std::string& dateStr);
    static bool isValidDay(int day, int month, int year);
};