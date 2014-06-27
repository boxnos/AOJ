#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    for (int x; (x = cin.get()) != -1;)
        cout << (char) (islower(x) ? x - 0x20 : x);

    return 0;
}
