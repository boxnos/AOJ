#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, p;

    getline(cin, s);
    getline(cin, p);

    s += s;
    cout << (s.find(p) != -1 ? "Yes" : "No") << endl;

    return 0;
}
