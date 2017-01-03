#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Date.h"


Date::Date(int month, int day, int year) {
    setMonth(month);
    setDay(day);
    setYear(year);
};

void Date::setMonth(int SMonth) {
    if (SMonth > 0 && SMonth <= 12)
        month = SMonth;
    else
        month = 1;
};

int Date::leapMonth() {
    if (getMonth() == 1 ||
        getMonth() == 3 ||
        getMonth() == 5 ||
        getMonth() == 7 ||
        getMonth() == 8 ||
        getMonth() == 10 ||
        getMonth() == 12
        )
        return 0;
    else if (
        getMonth() == 4 ||
        getMonth() == 6 ||
        getMonth() == 9 ||
        getMonth() == 11
        )
        return 1;
    else if (
        getMonth() == 2
        )
        return 2;
}

void Date::setDay(int SDay) {
    if (leapMonth() == 0) {
        if (SDay <= 31 && SDay > 0)
            day = SDay;
        else
            day = 1;
    }
    if (leapMonth() == 1) {
        if (SDay <= 30 && SDay > 0)
            day = SDay;
        else
            day = 1;
    }
    if (leapMonth() == 2 && getYear() % 4) {
        if (SDay <= 29 && SDay > 0)
            day = SDay;
        else
            day = 1;
    }
    else {
        if (SDay <= 28 && SDay > 0)
            day = SDay;
        else
            day = 1;
    }
};

void Date::setYear(int SYear) {
    year = SYear;
};

int Date::getMonth() {
    return month;
};

int Date::getDay() {
    return day;
}
int Date::getYear() {
    return year;
};

void Date::displayDate() {
    cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}