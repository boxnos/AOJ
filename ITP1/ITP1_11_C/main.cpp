#include <iostream>
#include <array>
#include <string>
using namespace std;

typedef array<int, 6> dice;

bool f(dice &d0, dice &d1)
{
	static const array<dice, 6> tbl = {
		0,1,2,3,4,5, 1,5,2,3,0,4, 2,1,5,0,4,3,
		3,1,0,5,4,2, 4,0,2,3,5,1, 5,1,3,2,4,0};

	for (dice t : tbl) {
		if (d0[t[0]] != d1[0])
			continue;
		int i = 0, j;
		do {
			j = 0;
			for (; j < 6 && d0[t[j]] == d1[j]; j++)
				;
			if (j == 6)
				return true;
			int tmp = t[1]; t[1] = t[2]; t[2] = t[4]; t[4] = t[3]; t[3] = tmp;
		} while (i++ < 4);
	}
	return false;
}

int main()
{
	dice d[2];

	for (auto &x: d) {
		for (int &y: x) {
			cin >> y;
		}
	}

	cout << (f(d[0], d[1]) ? "Yes" : "No") << endl;
}
