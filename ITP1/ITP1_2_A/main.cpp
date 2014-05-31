#include <iostream>
using namespace std;

string cmp(int a, int b)
{
    return (a == b) ? "==" : (a < b) ? "<" : ">";
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "a " << cmp(a, b) << " b" << endl;

    return 0;
}
