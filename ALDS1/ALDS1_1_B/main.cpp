#include <iostream>
#include <utility>
using namespace std;

int main()
{
	int a, b;
	for (cin >> a >> b; b; swap(a = a % b, b))
		;
	cout << a << endl;
}

/* vim: set ts=4 noet: */
