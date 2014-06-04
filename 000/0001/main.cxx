#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    int height;
    vector<int> top3;

loop:
    if (cin >> height) {
        for (auto it = top3.begin(); it != top3.end(); it++) {
            if (height > *it) {
                it = top3.insert(it, height);
                if (top3.size() > 3)
                    top3.pop_back();
                goto loop;
            }
        }
        if (top3.size() < 3)
            top3.push_back(height);
        goto loop;
    }

    for (auto h: top3)
        cout << h << endl;

    return 0;
}
