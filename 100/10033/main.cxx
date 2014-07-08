#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<stack <char>> blocks(n + 1);

    string s;
    int mount;
    for (; cin >> s >> mount && s != "quit";) {
        if (s == "push") {
            char c;
            cin >> c;
            blocks[mount].push(c);
        } else if (s == "move") {
            int to;
            cin >> to;
            blocks[to].push(blocks[mount].top());
            blocks[mount].pop();
        } else {
            cout << blocks[mount].top() << endl;
            blocks[mount].pop();
        }
    }

    return 0;
}
