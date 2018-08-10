#include <iostream>
#include <limits>

using namespace std;

class vec {
    int sz;
    double *elem;
public:
    vec(int s)
            : sz{s}, elem{new double[s]} {
        for (int i = 0; i < sz; i++)
            elem[i] = 0.0;
    }

    ~vec() { delete[] elem; }

    double get(int i) { return elem[i]; }

    void set(int i, double d) { elem[i] = d; }

    vec(const vec &arg)
            : sz{arg.sz}, elem{new double[arg.sz]} {
        copy(arg.elem, arg.elem + arg.sz, elem);
    }


    vec &operator=(const vec &a)
    {
        double *p = new double[a.sz];
        copy(a.elem, a.elem + a.sz, p);
        delete[] elem;
        elem = p;
        sz = a.sz;
        return *this;
    }

    double &operator[](int idx) const {
        return elem[idx];
    }
};

void f(int n) {

    vec v(n);
    v.set(2, 1.0);
    vec v2 = v;
    v2.set(2, 2.0);
    v.set(1, 3);
    v2.set(1, 4);
    cout << v[2] << ' ' << v2[2] << '\n';
    cout << v[1] << ' ' << v2[1] << '\n';

}



int main() {
    int i = 0;

    while (i < numeric_limits<int>::max()) {
        f(10);
        i++;
    }
    return 0;
}
