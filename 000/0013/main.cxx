#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> stack;

    for (int n; cin >> n;)
        if (n == 0) {
            cout << stack.front() << endl;
            stack.pop_front();
        } else
            stack.push_front(n);

    return 0;
}
