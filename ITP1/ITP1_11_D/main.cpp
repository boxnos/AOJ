#include <iostream>
#include <array>
#include <unordered_map>
using namespace std;

typedef unsigned long ul;
typedef array<ul, 6> dice;

bool f(int n)
{
	static const array<dice, 6> tbl = {
			0,1,2,3,4,5, 1,5,2,3,0,4, 2,1,5,0,4,3,
			3,1,0,5,4,2, 4,0,2,3,5,1, 5,1,3,2,4,0};
	dice d;
	unordered_map<ul, bool> db;
	array<ul, 24> r;

	while (n--) {
		for (ul &x: d)
			cin >> x;
		int i = 0;
		for (dice t: tbl) {
			for (int j = 0; j < 4; j++) {
				ul l = 0;
				for (int k = 0; k < 6; k++)
					l += (d[t[k]] + 1) << k * 10;
				if (db.count(l))
					return true;
				r[i * 4 + j] = l;
				ul x = t[1]; t[1] = t[2]; t[2] = t[4]; t[4] = t[3]; t[3] = x;
			}
			i++;
		}
		for (ul l : r)
			db[l] = true;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	cout << (f(n) ? "No" : "Yes") << endl;
}

/* vim: set ts=4 noet: */
