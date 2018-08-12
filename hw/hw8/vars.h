#ifndef OOPCAL_VERSION2_VARS_H
#define OOPCAL_VERSION2_VARS_H

#include "std_lib_facilities.h"

class Variable {
public:
    string name;
    double value;
};

double get_value(string s);

void set_value(string s, double d);


#endif //OOPCAL_VERSION2_VARS_H
