//
// Created by Shucheng Yan on 7/25/18.
//

#include "date.h"

Date::Date(int yy, Month mm, int dd)
        : y(yy), m(mm), d(dd) {
    if (!is_date(yy, mm, dd)) throw Invalid();
}


const Date &default_date() {
    static const Date dd(2000, Date::jan, 1);
    return dd;
}


Date::Date()
        : y(default_date().year()),
          m(default_date().month()),
          d(default_date().day()) {
}


int days_in_month(int y, Date::Month m);

void Date::add_day(int n) {

    if (n < 0) error("add_day(): can't handle negative n");
    while (days_in_month(y, m) < n + d) {
        add_month(1);

        n -= (days_in_month(y, m) - d);
        d = 0;
    }
    d += n;
}


void Date::add_month(int n) {
    if (n < 0) error("add_month(): can't handle negative n");


    if ((int) m + n > 12) {
        int k = int(m);
        while ((int) k + n > 12) {
            add_year(1);

            n -= 12 - (int) k;
            k = 0;
        }

        m = (Month) n;

    } else {
        int res = (int) m + n;

        m = (Month) res;
    }

}


void Date::add_year(int n) {
    if (m == feb && d == 29 && !leapyear(y + n)) {
        m = mar;
        d = 1;
    }
    y += n;
}


int days_in_month(int y, Date::Month m) {
    switch (m) {
        case Date::feb:
            return (leapyear(y)) ? 29 : 28;
        case Date::apr:
        case Date::jun:
        case Date::sep:
        case Date::nov:
            return 30;
        default:
            return 31;
    }
}

bool is_date(int y, Date::Month m, int d) {

    if (y <= 0) return false; // assume year has to be a positive number
    if (d <= 0) return false;
    if (days_in_month(y, m) < d) return false;

    return true;
}


bool leapyear(int y) {

    if (y % 4)
        return false;
    if (y % 100 == 0 && y % 400)
        return false;
    return true;
}


bool operator==(const Date &a, const Date &b) {
    return a.year() == b.year()
           && a.month() == b.month()
           && a.day() == b.day();
}


bool operator!=(const Date &a, const Date &b) {
    return !(a == b);
}

vector<string> m{"", "Janaury", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                 "November", "December"};


ostream &operator<<(ostream &os, const Date &d) {
    return os << m[d.month()]
              << " " << d.day()
              << ", " << d.year();
}


istream &operator>>(istream &is, Date &dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }
    dd = Date(y, Date::Month(m), d);
    return is;
}
