#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;

    while (cin >> s && s != "-") {
        int m, h;
        cin >> m;
        while (m-- && cin >> h)
            s = s.substr(h, s.size() - h) + s.substr(0, h);
        cout << s << endl;
    }

    return 0;
}
