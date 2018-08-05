#include <iostream>

using namespace std;

int main() {
    int i = 0;
    while (true) {
      double* a = new double[1000];
      cout << a[0] << " " << i << '\n';
      i++;
    }
    return 0;
}

