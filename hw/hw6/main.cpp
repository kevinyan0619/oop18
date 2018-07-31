
#include "std_lib_facilities.h"
using namespace std;

struct Reading { // a temperature reading
    int hour; // hour after midnight [0:23]
    double temperature; // in Fahrenheit
    double pressure;
};

inline void error(const string& s, int i);
int main()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname}; // ist reads from the file named iname
    if (!ist) error("can't open input file ",iname);

    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost {oname}; // ost writes to a file named oname
    if (!ost) error("can't open output file ",oname);

    vector<Reading> temps; // store the readings here
    int hour;
    double temperature;
    double pressure;
    char sep1;
    char sep2;
    while (ist >> hour >> sep1 >> temperature >> sep2 >> pressure) {
        if (hour < 0 || 23 < hour) error("hour out of range");
        temps.push_back(Reading{hour,temperature, pressure});
    }
    for (int i=0; i<temps.size(); ++i)
        ost << temps[i].hour << '\t'
            << temps[i].temperature << '\t' << temps[i].pressure << "\n";
}

