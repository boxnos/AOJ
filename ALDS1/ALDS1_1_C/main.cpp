#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int x)
{
    if (x == 2)
        return true;
    else if (x % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(x) ; i += 2)
        if (x % i == 0)
            return false;

    return true;
}

int main()
{
    int n, x, c = 0;

    cin >> n;
    while (n--) {
        cin >> x;
        if (is_prime(x))
            c++;
    }

    cout << c << endl;
}
