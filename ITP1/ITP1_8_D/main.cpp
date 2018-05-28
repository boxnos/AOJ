#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, p;
    bool res = false;

    getline(cin, s);
    getline(cin, p);

    for (int i = 0; i < s.size(); i++)
        if (s[i] == p[0]) {
            res = true;
            for (int j = 0; j < p.size(); j++)
                if (s[(i + j) % s.size()] != p[j]) {
                   res = false;
                   break; 
                }
            if (res)
                break;
        }

    cout << (res ? "Yes" : "No") << endl;

    return 0;
}
