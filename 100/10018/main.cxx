#include <iostream>
using namespace std;

inline char toggle_case(char c)
{
    return (0x41 <= c && c <= 0x5A || 0x61 <= c && c <= 0x7A) ? c ^ ' ' : c;
}

int main()
{
    for (int c; (c = cin.get()) != -1;)
        cout << toggle_case((char) c);

    return 0;
}
