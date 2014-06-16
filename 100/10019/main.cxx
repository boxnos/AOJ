#include <iostream>
using namespace std;

inline int sum_of_numbers(int x)
{
    int sum = 0;
    for (;x > 0; x /= 10)
        sum += x % 10;
    return sum;
}

int main()
{
    for (int x; cin >> x && x;)
        cout << sum_of_numbers(x) << endl;

    return 0;
}
