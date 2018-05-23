#include <iostream>
#include <vector>
#include <numeric>
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

    cout << accumulate(buffer.begin(), buffer.end(), 0,
                       [](int acc, int i) {
                            cout << i << " ";
                            return acc + i;
                       })
         << endl;

    return 0;
}
