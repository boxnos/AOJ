#include <iostream>
using namespace std;

template <typename T>
void my_swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
        if (a > b)
            my_swap(a, b);
        cout << a << " " << b << endl;
    }

    return 0;
}
