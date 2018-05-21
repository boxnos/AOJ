#include <iostream>
#include <vector>
using namespace std;

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

    while (cin >> m >> f >> r && !(m == -1 && f == -1 && r == -1))
        cout << grade() << endl;

    return 0;
}
