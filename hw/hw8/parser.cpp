#include "parser.h"
#include "token.h"
#include "vars.h"
#include "trigo.h"

double statement(Token_stream &ts) {

    Token t = ts.get();
    if (t.kind == name) {
        Token var = t;

        t = ts.get();
        if (t.kind == '=') {
            double d = expression(ts);
            set_value(var.name, d);
            return d;
        } else if (t.kind == print) {
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression(ts);
    }
    ts.putback(t);
    return expression(ts);
}

double expression(Token_stream &ts) {

    double left = term(ts);
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
            case '+':
                left += term(ts);
                t = ts.get();
                break;
            case '-':
                left -= term(ts);
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term(Token_stream &ts) {

    double left = expon(ts);
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
            case '*':
                left *= expon(ts);
                t = ts.get();
                break;
            case '/': {
                double d = expon(ts);
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = expon(ts);
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }

}

double expon(Token_stream &ts) {

    double left = primary(ts);
    Token t = ts.get();
    if (t.kind == power) {
        double d = primary(ts);
        return pow(left, d);
    } else {
        ts.putback(t);
        return left;
    }
}

double primary(Token_stream &ts) {

    Token t = ts.get();
    switch (t.kind) {
        case '(': {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case name: {
            Token next_t = ts.get();
            if (next_t.kind == '(') {
                double d = expression(ts);
                d = exec_func(t.name, d);
                t = ts.get();
                if (t.kind != ')') error("')' expected");

                return d;
            } else {
                ts.putback(next_t);
                return get_value(t.name);
            }
        }
        case '-':
            return -primary(ts);
        case '+':
            return primary(ts);
        default:
            error("primary expected");
    }
    return 0.0;
}

