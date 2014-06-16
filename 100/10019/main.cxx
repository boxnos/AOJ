#include <iostream>
#include <cctype>
using namespace std;

int sum_of_numbers(int first_number)
{
    int sum = first_number - '0';

    for (int c; isdigit(c = cin.get());)
        sum += c - '0';

    return sum;
}

int main()
{
    int sum = 0;
    bool start = true;
    for (int c; (c = cin.get()) != -1;) {
        if (c == '0')
            break;
        else
            cout << sum_of_numbers(c) << endl;
    }

    return 0;
}
