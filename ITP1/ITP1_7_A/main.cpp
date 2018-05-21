#include <iostream>
#include <vector>
using namespace std;

char grade(int m, int f, int r)
{
    int mf(m + f);
    return
        (m == -1 || f == -1)? 'F':
        (mf >= 80)? 'A':
        (mf >= 65)? 'B':
        (mf >= 50)? 'C':
        (mf >= 30)?
            (r >= 50)? 'C' : 'D' :
        'F';
}

int main(void)
{
    int m, f, r;

    while (cin >> m >> f >> r && !(m == -1 && f == -1 && r == -1))
        cout << grade(m, f, r) << endl;

    return 0;
}
