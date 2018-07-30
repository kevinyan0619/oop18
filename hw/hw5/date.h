//
// Created by Shucheng Yan on 7/29/18.
//

#ifndef DATEHW_DATE_H
#define DATEHW_DATE_H

#include "std_lib_facilities.h"

class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };


    Date();

    Date(int y, Month m, int d);


    class Invalid {
    };


    int day() const { return d; }

    Month month() const { return m; }

    int year() const { return y; }


    void add_day(int n);

    void add_month(int n);

    void add_year(int n);

private:
    int y;
    Month m;
    int d;
};


ostream &operator<<(ostream &os, const Date &d);

istream &operator>>(istream &is, Date &dd);

bool operator==(const Date &a, const Date &b);

bool operator!=(const Date &a, const Date &b);

bool is_date(int y, Date::Month m, int d);

bool leapyear(int y);

const Date &default_date();

#endif
