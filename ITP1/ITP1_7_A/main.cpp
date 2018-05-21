#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int m, f, r;

    while (cin >> m >> f >> r && !(m == -1 && f == -1 && r == -1)) {
        int mf(m + f);
        if (m == -1 || f == -1)
            cout << "F";
        else if (mf >= 80)
            cout << "A";
        else if (mf >= 65)
            cout << "B";
        else if (mf >= 50)
            cout << "C";
        else if (mf >= 30)
            if (r >= 50)
                cout << "C";
            else
                cout << "D";
        else
            cout << "F";
        cout << endl;
    }

    return 0;
}
