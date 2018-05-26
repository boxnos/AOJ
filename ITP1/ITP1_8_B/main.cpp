#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s;
    while (getline(cin, s) && s != "0") {
        int sum = 0;
        for (char c : s)
            sum += c - '0';
        cout << sum << endl;
    }

    return 0;
}
