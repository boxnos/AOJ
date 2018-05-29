#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string W, t;
    int n = 0;

    cin >> W;

    while (cin >> t && t != "END_OF_TEXT") {
        for (char &c : t)
            c = tolower(c);
        if (t == W)
            n++;
    }

    cout << n << endl;

    return 0;
}
