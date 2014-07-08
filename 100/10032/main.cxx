#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> blocks;

    for (string s; cin >> s && s != "quit";) {
        char c;
        if (s == "push") {
            cin >> c;
            blocks.push(c);
        } else {
            cout << blocks.top() << endl;
            blocks.pop();
        }
    }

    return 0;
}
