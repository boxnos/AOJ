#include <iostream>
#include <vector>
using namespace std;

char grade(int m, int f, int r)
{
        int mf(m + f);
        if (m == -1 || f == -1) return 'F';
        else if (mf >= 80) return 'A';
        else if (mf >= 65) return 'B';
        else if (mf >= 50) return 'C';
        else if (mf >= 30)
            if (r >= 50)
                return 'C';
            else
                return 'D';
        else
            return 'F';
}

int main(void)
{
    int m, f, r;

    while (cin >> m >> f >> r && !(m == -1 && f == -1 && r == -1))
        cout << grade(m, f, r) << endl;

    return 0;
}
