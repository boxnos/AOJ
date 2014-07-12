#include <iostream>
using namespace std;

int main()
{
    for (int w; cin >> w;) {
        bool first = true; // flag for output
        for (int x = 1; w; x <<= 1) {
            int result = w & x;
            if (result) {
                if (first) {
                    first = false;
                    cout << result;
                } else
                    cout << " " << result;
                w -= x;
            }
        }
        cout << endl;
    }

    return 0;
}
