#include <iostream>

using namespace std;

int main() {


    char c = 'a';
    int i = 4092;
    double d = 3.14;
    char*  cp = &c;
    int* ip = &i;
    double* dp = &d;

    cout << "value is " << c << ", pointer is " << static_cast<const void *>(&c)<< '\n';
    cout << "value is " << i << ", pointer is " << ip << '\n';
    cout << "value is " << d << ", pointer is " << dp << '\n';

    cout << "size of c is " << sizeof(c) << " , size of its pointer is " << sizeof(cp) << '\n';
    cout << "size of i is " << sizeof(i) << " , size of its pointer is " << sizeof(ip) << '\n';
    cout << "size of d is " << sizeof(d) << " , size of its pointer is " << sizeof(dp) << '\n';

    return 0;
}