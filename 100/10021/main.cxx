#include <iostream>
using namespace std;

int main()
{
    string minimum;
    int length;

    cin >> length;
    for(string buffer; cin >> buffer && length--;)
        if (!minimum.length() || minimum > buffer)
            minimum = buffer;

    cout << minimum << endl;

    return 0;
}
