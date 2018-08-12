#include "trigo.h"

#include <iostream>


std::map<const string, std::function<double(double)> > dispTable{

        {"sin",   [](double a) { return sin(a); }},
        {"cos",   [](double a) { return cos(a); }},
        {"tan",   [](double a) { return tan(a); }},

        {"asin",  [](double a) { return asin(a); }},
        {"acos",  [](double a) { return acos(a); }},
        {"atan",  [](double a) { return atan(a); }},

        {"sinh",  [](double a) { return sinh(a); }},
        {"cosh",  [](double a) { return cosh(a); }},
        {"tanh",  [](double a) { return tanh(a); }},


        {"exp",  [](double a) { return exp(a); }},

        {"sqrt",  [](double a) { return sqrt(a); }},
        {"cbrt",  [](double a) { return cbrt(a); }},

        {"log",   [](double a) { return log(a); }},
        {"log2",  [](double a) { return log2(a); }},
        {"log10", [](double a) { return log10(a); }},

        {"floor",  [](double a) { return floor(a); }},
        {"ceil",  [](double a) { return ceil(a); }},
        {"abs",  [](double a) { return abs(a); }},
};


double exec_func(string op_name, double arg) {
    try {
        return dispTable[op_name](arg);
    }
    catch (exception) {
        cout << "Error: undefined function " << op_name << '\n';
    }
    return 0.0;
}