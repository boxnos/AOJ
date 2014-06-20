#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int w, n;
    char comma;

    cin >> w >> n;

    vector<int> lines(w);
    iota(lines.begin(), lines.end(), 1);

    for (int a, b; cin >> a >> comma >> b;)
        swap(lines[a - 1], lines[b - 1]);

    for (auto x: lines)
        cout << x << endl;

    return 0;
}
