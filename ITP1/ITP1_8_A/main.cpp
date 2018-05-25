#include <iostream>
#include <cctype>
using namespace std;

int main(void)
{
    char c;
    while(cin.get(c))
        cout << (char) (islower(c) ? toupper(c) : tolower(c));

    return 0;
}
