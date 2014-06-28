#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    for (int x; (x = cin.get()) != -1;)
        cout << (char) toupper(x);

    return 0;
}
