#include <iostream>
using namespace std;

inline char toggle_case(char c)
{
    char upper = c & ~' ';
    return (0x41 <= upper && upper <= 0x5A) ? c ^ ' ' : c;
}

int main()
{
    for (int c; (c = cin.get()) != -1;)
        cout << toggle_case((char) c);

    return 0;
}
