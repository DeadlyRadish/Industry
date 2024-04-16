#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <string>

class Date {
public:
    struct BadDate;
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

private:
    static std::string monthNames [12];
    static bool defaultSet;
    static Date defaultDate;

    int _day, _month, _year;
    bool leapYear(const int) const;
    void fillDate(int d, Month m, int y);
    void checkIllFormed();
    bool isIllFormed() const;
    void setVal(int&, const int, const int);

public:
    static void setDefault(const int d = 1, Month = Month(1), const int y = 2000);
    static void showDefault(std::ostream& os);
    static const std::string monthNameByNumber(const int);

    Date(
        int d = (Date::defaultSet)?Date::defaultDate.day():1,
        Month m = (Date::defaultSet)?Date::defaultDate.month():Month(1),
        int y = (Date::defaultSet)?Date::defaultDate.year():2000
        );
    Date(int d, int m, int y);
    Date(const Date&);
    Date& operator=(const Date&);
    ~Date();

    int day() const;
    Month month() const;
    int year() const;

    const std::string getMonthName() const;

    void setDay(const int);
    void setMonth(const int);
    void setYear(const int);

    const Date& operator++();
    const Date  operator++(int);
    const Date& operator--();
    const Date  operator--(int);
};

struct Date::BadDate {
    int _day, _month, _year;
    BadDate(int d, int m, int y);
};

std::ostream& operator<<(std::ostream&, const Date&);
std::ostream& operator<<(std::ostream&, const Date::BadDate&);

#endif
