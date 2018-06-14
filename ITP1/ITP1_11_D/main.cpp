#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

typedef array<int, 6> dice;

ostream &operator<<(ostream &o,dice &v)
{
    for(size_t i=0;i<v.size();i++)
    {if(i>0)o<<" ";o<<v[i];}
    return o;
}

bool cmp(dice &d0, dice &d1)
{
    static const array<dice, 6> tbl = {
            0,1,2,3,4,5, 1,5,2,3,0,4, 2,1,5,0,4,3,
            3,1,0,5,4,2, 4,0,2,3,5,1, 5,1,3,2,4,0};

    for (dice t : tbl) {
            if (d0[t[0]] != d1[0])
                    continue;
            for (int i = 0, j; i < 4; i++) {
                    for (j = 0; j < 6 && d0[t[j]] == d1[j]; j++)
                            ;
                    if (j == 6)
                            return true;
                    int tmp = t[1]; t[1] = t[2]; t[2] = t[4]; t[4] = t[3]; t[3] = tmp;
            }
    }
    return false;
}

bool find(int n)
{
    vector<dice> d(n);

    for (int &a: d[0])
        cin >> a;

    for (int i = 1; i < n; i++) {
        for (int &a: d[i])
            cin >> a;
        for (int j = 0; j < i; j++)
            if(cmp(d[i], d[j]))
                return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    cout << (find(n) ? "No" : "Yes") << endl;
}
