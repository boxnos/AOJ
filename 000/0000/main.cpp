#include <iostream>
using namespace std;

#define range(bind, start, end) for (int bind = start; bind <= end; bind++)

int main()
{
    range (i, 1, 9)
        range (j, 1, 9)
            cout << i << "x" << j << "=" << i * j << endl;

    return 0;
}
