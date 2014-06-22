#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    for (int n; cin >> n;)
        if (n == 0) {
            cout << s.top() << endl;
            s.pop();
        } else
            s.push(n);

    return 0;
}
