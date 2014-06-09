#include <iostream>
#include <functional>
using namespace std;

function<int (int, int)> make_lambda(char &op)
{
    switch (op) {
    case '+': return [](int a, int b) {return a + b;}; break;
    case '-': return [](int a, int b) {return a - b;}; break;
    case '*': return [](int a, int b) {return a * b;}; break;
    case '/': return [](int a, int b) {return a / b;}; break;
    }
}

int main()
{
    int a, b;
    char op;

    while (cin >> a >> op >> b && op != '?')
        cout << make_lambda(op)(a, b) << endl;

    return 0;
}
