#include <iostream>
using namespace std;

template <typename... T> bool bind(T&&... a) { return (bool) (cin >> ... >> a); }
template <typename... T> bool is_valid(T... args) { return (... && (args == -1)); }

int main(void)
{
    int m, f, r;

    auto grade = [&]() {
        int mf(m + f);
        return
            (m == -1 || f == -1)? 'F':
            (mf >= 80)? 'A':
            (mf >= 65)? 'B':
            (mf >= 50)? 'C':
            (mf >= 30)?
                (r >= 50)? 'C' : 'D' :
            'F';
    };

    while (bind(m, f, r) && !is_valid(m, f, r))
        cout << grade() << endl;

    return 0;
}
