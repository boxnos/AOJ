#include <iostream>
#include <string>
using namespace std;

string search(string s, string p)
{
    for (int i = 0, j; i < s.size(); i++) {
        for (j = 0; j < p.size() && s[(i + j) % s.size()] == p[j]; j++)
            ;
        if (j >= p.size())
            return "Yes";
    }
    return "No";
}

int main()
{
    string s, p;

    getline(cin, s);
    getline(cin, p);

    cout << search(s, p) << endl;

    return 0;
}
