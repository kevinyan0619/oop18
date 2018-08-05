#ifndef OOPCAL_VERSION2_PARSER_H
#define OOPCAL_VERSION2_PARSER_H
#include "std_lib_facilities.h"
#include "token.h"

double statement(Token_stream &ts);

double expression(Token_stream &ts);

double term(Token_stream &ts);

double expon(Token_stream &ts);

double primary(Token_stream &ts);

#endif //OOPCAL_VERSION2_PARSER_H
