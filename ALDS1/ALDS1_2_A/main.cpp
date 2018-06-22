#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n, c = 0;
	cin >> n;
	vector<int> a(n);

	for (int &x: a)
		cin >> x;

	for (auto i = a.begin(), e = a.end() - 1; i != e; i++)
		for (auto j = e; j != i; j--)
			if (*j < *(j - 1)) {
				swap(*j, *(j - 1));
				c++;
			}

	for (int &x: a)
		cout << (&x != &a[0] ? " " : "") << x;

	cout << endl << c << endl;
}
