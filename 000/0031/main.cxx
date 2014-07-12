#include <iostream>
using namespace std;

int main()
{
    for (int w; cin >> w;) {
        bool first = true; // flag for output
        for (int x = 1; w; x <<= 1) {
            if (w & x) {
                if (first) {
                    first = false;
                    cout << x;
                } else
                    cout << " " << x;
                w -= x;
            }
        }
        cout << endl;
    }

    return 0;
}
