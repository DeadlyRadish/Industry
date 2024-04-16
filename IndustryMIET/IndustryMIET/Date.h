#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <string>

class Date {
private:
    int day, month, year;
    bool leapYear(int);
    bool isIllFormed(int, int, int);
public:
    Date();
    Date(int, int, int);

    int getDay();
    int getMonth();
    int getYear();

    void setDay(int);
    void setMonth(int);
    void setYear(int);
};


std::ostream& operator<<(std::ostream&, Date&);

#endif