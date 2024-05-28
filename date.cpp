#include "date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int Date::daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }

}

void Date::incrementDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

Date Date::operator++(int) {
    Date temp = *this;
    incrementDay();
    return temp;
}

std::string Date::formatDateAsString() {
    std::ostringstream oss;
    oss << day << "." << month << "." << year;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "." << date.month << "." << date.year;
    return os;
}

bool Date::operator<(const Date& other) {
    if (year != other.year) {
        return year < other.year;
    }
    if (month != other.month) {
        return month < other.month;
    }
    return day < other.day;
}

bool Date::operator>(const Date& other) {
    if (year != other.year) {
        return year > other.year;
    }
    if (month != other.month) {
        return month > other.month;
    }
    return day > other.day;
}

bool Date::operator==(const Date& other) {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) {
    return !(*this == other);
}

Date& Date::operator=(const std::string& dateStr) {
    std::istringstream iss(dateStr);
    char delimiter;
    iss >> day >> delimiter >> month >> delimiter >> year;
    return *this;
}

bool Date::isValidDate(const std::string& dateStr) {
    Date temp(0, 0, 0);
    std::istringstream iss(dateStr);
    char delimiter;
    iss >> temp.day >> delimiter >> temp.month >> delimiter >> temp.year;
    return isValidDay(temp.day, temp.month, temp.year);
}

bool Date::isValidDay(int day, int month, int year) {
    if (day <= 0 || month <= 0 || month > 12 || year < 0) {
        return false;
    }

    int daysInMonth;
    switch (month) {
    case 2:
        daysInMonth = isLeapYear(year) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
    }

    return day <= daysInMonth;
}
