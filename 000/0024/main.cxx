#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (double v; cin >> v;)
        cout << ceil((4.9 * v * v / 9.8 / 9.8 + 5) / 5) << endl;

    return 0;
}
