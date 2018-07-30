//#include "token.h"
#include <vector>
#include <iostream>

using namespace std;

class Token {
public:
    
    Token(char k, double v) : kind(k), value(v) {
        
    }
    
    Token(char k) : kind(k), value(0) {
        
    }
    char kind;
    double value;
};


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
            return Token(ch);
            
            
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
            
        default:
            return Token(ch,1);
            
    }
}



int main() {
    vector<Token> tokens;
    
 //   Token t = getToken();
    
//    while (t.kind != 'q') {
//        tokens.push_back(t);
//        t = getToken();
//
//    }
    
    for (Token t = getToken(); t.kind != 'q'; t = getToken()) {
        tokens.push_back(t);
    }
    
    for(Token tok : tokens) {
        if (tok.kind == '8')
            cout << "A number token with val = " << tok.value << '\n';
        else if (tok.value == 0)
            cout << "A token of kind " << tok.kind << '\n';
        else
            cout << "We received an invalid token of value " << tok.kind << '\n';
            
        }
    
    return 0;
    
    
}
