#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int r, c, n;

    cin >> r >> c;
    vector<int> buffer(c);

    while (r--) {
        int sum_row = 0;
        for (int i = 0; i < c; i++) {
            cin >> n;
            sum_row += n;
            buffer[i] += n;
            cout << n << " ";
        }
        cout << sum_row << endl;
    }

    int sum = 0;
    for (int x: buffer) {
        sum += x;
        cout << x << " ";
    }
    cout << sum << endl;

    return 0;
}
