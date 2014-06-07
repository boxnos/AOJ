#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    for (double a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f; )
        cout << fixed << setprecision(3)
            << (b*f - c*e)/(b*d - a*e) + 0.0
            << " "
            << (a*f - c*d)/(a*e - b*d) + 0.0 << endl;

    return 0;
}
