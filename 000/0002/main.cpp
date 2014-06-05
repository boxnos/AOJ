#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    while(cin >> a >> b) {
        int sum = a + b;
        cout << (sum == 0 ? 1 : (int) log10(sum) + 1) << endl;
    }

    return 0;
}
