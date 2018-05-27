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

    for (int i = 0; i < v.size(); i++)
        cout << (char) ('a' +  i) << " : " << v[i] << endl;

    return 0;
}
