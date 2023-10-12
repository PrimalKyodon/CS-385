#include <iostream>
using namespace std;

void pass_by_value(int k) {
    k = 10;
}

void pass_by_pointer(int *k) {
    *k = 10;
}

void pass_by_reference(int &k) {
    k = 10;
}

int main() {
    int x;
    x = 5;
    int *z;
    z = &x;

    cout << x << " " << &x << " " << z << " " << &z << endl;

    cout << "z* is: " << *z << endl;


    pass_by_value(x);
    cout << "x is: " << x << endl;

    pass_by_pointer(x);
    cout << "x is: " << x << endl;

    pass_by_reference(&x);
    cout << "x is: " << x << endl;

    int *values = new int[x];

    for (int i = 0; i < x; i++) {
        //both lines assign the respective element in values to i; one uses standard convention the other pointers
        values[i] = i;
        *(values + i) = i;
    }



}
