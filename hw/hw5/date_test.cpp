#include <iostream>
#include "date.h"

int main() {

    Date d;
    Date t;
    Date q(1600, Date::jan, 1);

    while (cin) {

        char op;

        std::cout << "Please enter a date in format (YYYY,MM,DD), enter q to quit:" << std::endl;

        cin >> op;

        if (op == 'q')
            exit(0);
        else
            cin.putback(op);
        cin >> d;

        cout << "The date entered is: " << '\n';
        cout << d << '\n' << '\n';


        cout << "add 100 days to the above date: \n";
        d.add_day(100);
        cout << d << '\n' << '\n';

        t = Date(d.year(), d.month(), d.day());

        if (t == d)
            cout << "== operator passed" << '\n';
        else
            cout << "== operator failed" << '\n';


        if (t != q)
            cout << "!= operator passed" << '\n' << '\n';
        else
            cout << "!= operator failed" << '\n' << '\n';


        cout << "add 30 month to the above date: \n";
        d.add_month(30);
        cout << d << '\n' << '\n';

        t = Date(d.year(), d.month(), d.day());

        if (t == d)
            cout << "== operator passed" << '\n';
        else
            cout << "== operator failed" << '\n';


        if (t != q)
            cout << "!= operator passed" << '\n' << '\n';
        else
            cout << "!= operator failed" << '\n' << '\n';


        cout << "add 10 year to the above date: \n";
        d.add_year(10);
        cout << d << '\n' << '\n';

        t = Date(d.year(), d.month(), d.day());

        if (t == d)
            cout << "== operator passed" << '\n';
        else
            cout << "== operator failed" << '\n';


        if (t != q)
            cout << "!= operator passed" << '\n' << '\n';
        else
            cout << "!= operator failed" << '\n' << '\n';


    }
    return 0;
}