#include <iostream>
#include <sstream>
using namespace std;

int max(int n, int m) {
    if (n > m) {
        return n;
    } else {
        return m;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <int> <int>" << endl;
        return 1;
    }
    int n, m;
    istringstream iss;

    iss.str(argv[1]);
    if (!(iss >> n)) {
        cerr << "Err: first common dline arg must be int" << endl;
    }
    iss.clear();

    iss.str(argv[2]);
    if (!(iss >> m)) {
        cerr << "Err: second common dline arg must be int" << endl;
    }

    cout << "n is: " << n << endl;
    cout << "m is: " << m << endl;
    cout << "max(" << n << ", " << m << ") is " << max(n,m) << endl;

    return 0;
}
