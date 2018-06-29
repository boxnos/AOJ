#include <iostream>
using namespace std;

int main()
{
	int a, b, c, n = 0;

	cin >> a >> b >> c;

	for (; a <= b; a++)
		if (c % a == 0)
			n++;

	cout << n << endl;
}
