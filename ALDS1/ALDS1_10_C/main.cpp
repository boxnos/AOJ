#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
	int n;
	cin >> n;

	string x, y;
	vector<vi> t(1001, vi(1001));

	while(n--) {
		cin >> x >> y;
		int xs = x.size(), ys = y.size();
		for (int i = 1; i <= xs; i++)
			for (int j = 1; j <= ys; j++)
				t[i][j] = x[i - 1] == y[j - 1] ?
					max(t[i - 1][j], max(t[i][j - 1], t[i - 1][j - 1] + 1)) :
					max(t[i - 1][j], t[i][j - 1]);
		cout << t[xs][ys] << endl;
	}
}

/* vim: set ts=4 noet: */
