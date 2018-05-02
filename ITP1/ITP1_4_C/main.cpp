#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    char op;

    while (cin >> a >> op >> b) {
        int res;
        switch (op) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        case '?':
            goto end;
        }
        cout << res << endl;
    }

end:

    return 0;
}
