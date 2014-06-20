#include <iostream>
using namespace std;

int main()
{
    for (string str; cin >> str && str != "-";) {
        int m, sum = 0;
        cin >> m;
        for (int h; m-- && cin >> h;)
            sum = (sum + h) % str.size();
        cout << str.substr(sum, str.size()) + str.substr(0, sum) << endl;
    }

    return 0;
}
