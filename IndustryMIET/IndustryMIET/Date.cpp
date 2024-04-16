#include "Date.h"

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int input_day, int input_month, int input_year) {
    if (isIllFormed(input_day, input_month, input_year)) {
        throw std::invalid_argument("received negative value");
    }else{
        day = input_day;
        month = input_month;
        year = input_year;
    }
}

bool Date::leapYear(int y){
    if (y % 4) {
        return false;
    }
    if (y % 100) {
        return true;
    }
    if (y % 400) {
        return false;
    }
    return true;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::setDay(int input_day) {

}

void Date::setMonth(int input_month) {

}

void Date::setYear(int input_year) {

}

std::ostream& operator<<(std::ostream& os, Date& d) {
    os << d.getDay() << '.' << d.getMonth() << '.' << d.getYear();
    return os;
}

bool Date::leapYear(int y){
    if (y % 4) {
        return false;
    }
    if (y % 100) {
        return true;
    }
    if (y % 400) {
        return false;
    }
    return true;
}

bool Date::isIllFormed(int d, int m, int y){
    if (y < 0) {
        return true;
    }
    if (m < 1 || 12 < m) {
        return true;
    }
    int maxDay = (7 < m) ? 31 - m % 2 : 30 + m % 2;
    if (m == 2) {
        if (leapYear(y)) {
            maxDay = 29;
        }
        else {
            maxDay = 28;
        }
    }
    if (d < 1 || maxDay < d) {
        return true;
    }

    return false;
}