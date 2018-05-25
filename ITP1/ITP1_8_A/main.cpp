#include <iostream>
#include <cctype>
using namespace std;

int main(void)
{
    char c;
    while(cin.get(c))
        cout << (char) (islower(c) ? toupper(c) : isupper(c) ? tolower(c) : c);

    return 0;
}
