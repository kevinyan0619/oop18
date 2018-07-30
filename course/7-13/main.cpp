//#include "token.h"
#include <vector>
#include <iostream>

using namespace std;




class Token {
public:
    
    Token() {
        
    }
    
    Token(char k, double v) : kind(k), value(v) {
        
    }
    char kind;
    double value;
};


class Token_stream {
public:
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

double expression();
double term();
double primary();

Token getToken();


int main() {
    //    vector<Token> tokens;
    //
    //    Token t = getToken();
    //
    //    while (t.kind != 'q') {
    //        tokens.push_back(t);
    //        t = getToken();
    //
    //    }
    //
    //    for(Token tok : tokens) {
    //        if (tok.kind == '8')
    //            cout << "val = " << tok.value << '\n';
    //        else
    //            cout << "Token kind = " << tok.kind << '\n';
    //    }
    //
    
    
    
    Token_stream ts;
    
    Token t = ts.get();
    
    while (t.kind != 'q') {
        if (t.kind == '8')
            cout << "val = " << t.value << '\n';
        else
            cout << "Token kind = " << t.kind << '\n';
        t = ts.get();
    }
    
    return 0;
    
    
}



Token Token_stream::get() {
    if(full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch(ch) {
        case ';':
        case 'q':
        case '(': case ')': case '+': case '-': case '/': case '*': case '%':
            return Token(ch,0);
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token('8', val);
        }
        default:
            return Token('i', double(ch));
    }
    return Token('q', 0.0);
}

void Token_stream::putback(Token t)
{
    buffer =t;
    full = true;
}

Token getToken() {
    
    char ch;
    
    cin >> ch;
    switch(ch) {
        case ';':
        case 'q':
        case '(':
        case ')':
        case '+':
        case '-':
        case '/':
        case '*':
            return Token(ch, 0);
            
            
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token('8', val);
        }
    }
}




double expression() {
    
    double left = term(); // read and evaluate a Term
    Token t = get_token(); // get the next token
    switch (t.kind ) { // see which kind of token that is
        case '+ ':
            return left + expression(); // read and evaluate an Expression,
            // then do an add
        case '–':
            return left – expression(); // read and evaluate an Expression,
            // then do a subtraction
        default:
            return left; // return the value of the Term
    }
}




