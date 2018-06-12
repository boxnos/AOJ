#include <iostream>
#include <array>
#include <map>
#include <string>
using namespace std;

struct dice {
	array<int, 6> a;
	map<int, int> m;
};

int main()
{
	dice d[2];
	array<array<string, 6>, 6> tbl = {
		"", "2345", "4135", "1425", "3215", "",
		"3254", "", "0534", "5024", "", "2304",
		"1453", "5043", "", "", "0513", "4103",
		"4152", "0542", "", "", "5012", "1402",
		"2351", "", "5031", "0521", "", "3201",
		"", "3240", "1430", "4120", "2310", ""};

	for (auto &x: d) {
		int i = 0;
		for (int &y: x.a) {
			cin >> y;
			x.m[y] = i++;
		}
	}

	bool flag = false;
	int i = 2;
	for (auto c: tbl[ d[0].m[d[1].a[0]] ][ d[0].m[d[1].a[1]] ]) {
		if (d[0].a[c - '0'] != d[1].a[i++]) {
			flag = false;
			break;
		}
		flag = true;
	}

	cout << (flag ? "Yes" : "No") << endl;
}
