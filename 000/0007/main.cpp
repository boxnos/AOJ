#include <iostream>
#include <cmath>
using namespace std;

int debt_in_weeks(int weeks)
{
    int borrow = 100000;
    for (;weeks != 0 ; weeks--)
        borrow = ceil((borrow * 1.05) / 1000) * 1000;

    return borrow;
}

int main()
{
    int weeks;
    cin >> weeks;
    cout << debt_in_weeks(weeks)<< endl;

    return 0;
}
