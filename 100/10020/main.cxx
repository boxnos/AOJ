#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    vector<int> charactors('z' - 'a' + 1, 0);

    for (char c; cin >> c;)
        if (isalpha(c))
            charactors[(c | ' ') - 'a']++;

    for (int i = 0; i < charactors.size(); i++)
        cout << (char) ('a' + i) << " : " << charactors[i] << endl;

    return 0;
}
