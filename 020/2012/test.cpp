#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int  n = 27 * 27 * 27;
    cout << (int) cbrtf(n) << endl // 27
        << (int) cbrtl(n) << endl // 27
        << (int) cbrt((float) n) << endl // 27
        << (int) cbrt((double) n) << endl // 26
        << (int) cbrt((long double) n) << endl // 27
        << (int) cbrt(n) << endl // 26
        << (int) sqrt(27 * 27) << endl; // 26
}
