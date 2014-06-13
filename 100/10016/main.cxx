#include <iostream>
using namespace std;

inline char grade(int &m, int &f, int &r)
{
    if (m == -1 || f == -1)
        return 'F';

    // binary search
    int sum = m + f;
    return (sum >= 50) ?
            (sum >= 65) ?
                (sum >= 80) ? 'A' : 'B'
            : 'C'
        : (sum >= 30) ?
            (r >= 50) ? 'C' : 'D'
            : 'F';
}

int main()
{
    for(int m, f, r; cin >> m >> f >> r && !(m == -1 && f == -1 && r == -1);)
        cout << grade(m, f, r) << endl;

    return 0;
}
