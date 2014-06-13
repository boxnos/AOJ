#include <iostream>
using namespace std;

inline char grade(int &m, int &f, int &r)
{
    if (m == -1 || f == -1)
        return 'F';

    // binary search
    int sum = m + f;
    if (sum >= 50)
        if (sum >= 65)
            if (sum >= 80)
                return 'A';
            else
                return 'B';
        else
            return 'C';
    else
        if (sum >= 30)
            if (r >= 50)
                return 'C';
            else
                return 'D';
        else
            return 'F';
}

int main()
{
    for(int m, f, r; cin >> m >> f >> r && !(m == -1 && f == -1 && r == -1);)
        cout << grade(m, f, r) << endl;

    return 0;
}
