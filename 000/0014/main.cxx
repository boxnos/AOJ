#include <iostream>
using namespace std;

int main()
{
    for (int d; cin >> d;) {
        int n = 600 / d - 1;
        cout << n * (2 * n + 1) * (n + 1) / 6 * d * d * d << endl;
    }

    return 0;
}
