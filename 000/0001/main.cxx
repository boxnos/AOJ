#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

inline void make_top3(vector<int> &top3, int height) {
    for (auto it = top3.begin(); it != top3.end(); it++) {
        if (height > *it) {
            it = top3.insert(it, height);
            if (top3.size() > 3)
                top3.pop_back();
            return;
        }
    }
    if (top3.size() < 3)
        top3.push_back(height);
    return;
}

int main()
{
    int height;
    vector<int> top3;

    while (cin >> height)
        make_top3(top3, height);

    for (auto h: top3)
        cout << h << endl;

    return 0;
}
