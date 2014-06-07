#include <iostream>
using namespace std;

int GCD(int a,int b)
{
    while (b != 0) {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

int main()
{
    for (int a, b; cin >> a >> b;)
        cout << GCD(a, b) << " " << LCM(a, b) << endl;

    return 0;
}
