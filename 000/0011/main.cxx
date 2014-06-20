#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int w, n;
    char c;

    cin >> w >> n;

    list<vector <int>> routes;

    for (vector<int> r(2); n-- && cin >> r[0] >> c >> r[1];)
        routes.push_front(r);

    for (int i = 1, pos = i; i <= w; pos = ++i) {
        for (auto r: routes)
            if (r[0] == pos)
                pos = r[1];
            else if(r[1] == pos)
                pos = r[0];

        cout << pos << endl;
    }

    return 0;
}
