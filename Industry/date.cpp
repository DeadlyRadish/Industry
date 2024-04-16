#include "date.h"

Date::BadDate::BadDate(int d, int m, int y)
    : _day(d), _month(m), _year(y) {

      };

std::string Date::monthNames[12] = {
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};
bool Date::defaultSet = true;
Date Date::defaultDate = Date(1, 1, 2000);

void Date::setDefault(const int d, Month m, const int y) {
    Date::defaultDate.setDay(d);
    Date::defaultDate.setMonth(m);
    Date::defaultDate.setYear(y);
    Date::defaultSet = true;
}
void Date::showDefault(std::ostream& os) {
    os << Date::defaultDate;
}
const std::string Date::monthNameByNumber(const int n) {
    return Date::monthNames[n-1];
}

Date::Date(int d, Month m, int y)
    : _day(d), _month(m), _year(y) {
    checkIllFormed();
}
Date::Date(int d, int m, int y)
    : _day(d), _month(Month(m)), _year(y) {
    checkIllFormed();
}
Date::Date(const Date& that)
    : _day(that.day()), _month(that.month()), _year(that.year()) {
    checkIllFormed();
}
void Date::checkIllFormed() {
    if(isIllFormed()) {
        BadDate bd = BadDate(day(), month(), year());
        *this = Date::defaultDate;
        throw bd;
    }
}
Date& Date::operator=(const Date& that) {
    fillDate(that.day(), that.month(), that.year());
    return *this;
}
Date::~Date(void) {

}

int Date::day() const {
    return _day;
}
Date::Month Date::month() const {
    return Month(_month);
}
int Date::year() const {
    return _year;
}

const std::string Date::getMonthName() const {
    return Date::monthNameByNumber(month());
}

void Date::setDay(const int d) {
    setVal(_day, d, day());
}
void Date::setMonth(const int m) {
    setVal(_month, m, month());
}
void Date::setYear(const int y) {
    setVal(_year, y, year());
}
void Date::setVal(int& val, const int newVal, const int prevVal) {
    val = newVal;
    if(isIllFormed()) {
        BadDate bd = BadDate(day(), month(), year());
        val = prevVal;
        throw bd;
    }
}

const Date& Date::operator++() {
    setDay(day() + 1);
    return *this;
}
const Date Date::operator++(int) {
    setDay(day() + 1);
    return *this;
}
const Date& Date::operator--() {
    setDay(day() - 1);
    return *this;
}
const Date Date::operator--(int) {
    setDay(day() - 1);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.day() << '.' << d.getMonthName() << '.' << d.year();
    return os;
}
std::ostream& operator<<(std::ostream& os, const Date::BadDate& bd) {
    os << bd._day << '.' << Date::monthNameByNumber(bd._month) << '.' << bd._year;
    return os;
}

bool Date::leapYear(const int y) const {
    /*
    1.If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
    2.If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
    3.If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
    4.The year is a leap year (it has 366 days).
    5.The year is not a leap year (it has 365 days).
    */
    if(y%4) {
        return false;
    }
    if(y%100) {
        return true;
    }
    if(y%400) {
        return false;
    }
    return true;
}
void Date::fillDate(int d, Month m, int y) {
    setDay(d);
    setMonth(m);
    setYear(y);
}

bool Date::isIllFormed() const {
    const int d(day()), m(month()), y(year());

    //check year
    if(y < 0) {
        return true;
    }

    //check month
    if(m < 1 || 12 < m) {
        return true;
    }

    //check day
    int maxDay((7<m)?31-m%2:30+m%2);
    if(m == 2) {
        if(leapYear(y)) {
            maxDay = 29;
        } else {
            maxDay = 28;
        }
    }
    if(d<1 || maxDay<d) {
        return true;
    }

    return false;
}
