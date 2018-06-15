#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef array<int, 6> dice;
struct DB {
    map<int, DB> d;
};

bool append(dice &d, int i, DB &db)
{
    int f = d[i];
    if (!db.d.count(f)) {
        db.d[f] = *(new DB);
        if (i == 5)
            return false;
    } else if (i == 5)
        return true;
    return append(d, i + 1, db.d[f]);
}

bool f(int n)
{
    static const array<dice, 6> tbl = {
            0,1,2,3,4,5, 1,5,2,3,0,4, 2,1,5,0,4,3,
            3,1,0,5,4,2, 4,0,2,3,5,1, 5,1,3,2,4,0};
    DB db;
    dice d, tmp;

    while (n--) {
        for (int &a: d)
            cin >> a;
        for (dice t: tbl)
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 6; j++)
                    tmp[j] = d[t[j]];
                if (append(tmp , 0, db))
                    return true;
                if (i != 3) {
                    int x = t[1]; t[1] = t[2]; t[2] = t[4]; t[4] = t[3]; t[3] = x;
                }
            }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    cout << (f(n) ? "No" : "Yes") << endl;
}
