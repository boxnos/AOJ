#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string t, h;
	int n, tp = 0, hp = 0;

	cin >> n;

	while (n-- && cin >> t >> h)
		if (t == h)
			tp++, hp++;
		else if (t > h)
			tp += 3;
		else
			hp += 3;

	cout << tp << " " << hp << endl;

	return 0;
}
