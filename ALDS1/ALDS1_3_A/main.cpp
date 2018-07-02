#include <iostream>
#include <stack>
#include <string>
#include <functional>
using namespace std;

int main()
{
	stack<int> s;

	auto g = [&]() {int u = s.top(); s.pop(); return u;};
	auto f = [&](auto op) {int b = g(), a = g(); s.push(op(a, b));};

	string t;
	while (cin >> t) {
		switch (t[0]) {
		case '+': f(plus<int>()); break;
		case '-': f(minus<int>()); break;
		case '*': f(multiplies<int>()); break;
		default: s.push(stoi(t));
		}
	}
	cout << s.top() << endl;
}

/* vim: set ts=4 noet: */
