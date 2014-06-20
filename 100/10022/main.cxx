#include <iostream>
#include <cctype>
using namespace std;

bool find(string a, string b)
{
    auto ai = a.begin(), bi = b.begin();

    for (; ai != a.end() || bi != b.end() ; ai++, bi++)
        if (tolower(*ai) != tolower(*bi))
            return false;

    return (ai == a.end() && bi == b.end()) ? true : false;
}

int main()
{
    string input;
    int count = 0;

    cin >> input;

    for (string buffer; cin >> buffer && buffer != "END_OF_TEXT";)
        if (find(input, buffer))
            count++;

    cout << count << endl;

    return 0;
}
