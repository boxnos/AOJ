#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    char c;
    vector<int> v('z' - 'a' + 1);

    while (cin.get(c))
        if (isalpha(c))
            v[tolower(c) - 'a']++;

    for (c = 'a'; c <= 'z'; c++)
        cout << c << " : " << v[c - 'a'] << endl;

    return 0;
}
