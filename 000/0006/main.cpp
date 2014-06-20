#include <iostream>
#include <algorithm>
using namespace std;

#define all(bind) bind.begin(), bind.end()

int main()
{
    string s;

    cin >> s;
    reverse(all(s));
    cout << s << endl;

    return 0;
}
