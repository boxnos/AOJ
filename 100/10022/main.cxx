#include <iostream>
#include <algorithm>
#include <locale>
using namespace std;

#define all(bind) (bind).begin(), (bind).end()

int main()
{
    string input;
    int count = 0;

    cin >> input;
    transform(all(input), input.begin(), [] (char a) {return tolower(a);});

    for (string buffer; cin >> buffer && buffer != "END_OF_TEXT";)
        if (equal(all(input), buffer.begin(), [](char a,char b) {return a == tolower(b);}))
            count++;

    cout << count << endl;

    return 0;
}
