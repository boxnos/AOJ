#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;

	for (int i = n, k; i--;) {
		cin >> k >> k;
		for (int j = 0, v; j < k; j++) {
			cin >> v;
			q.push(v);
		}

		for (int j = 1; j <= n; j++) {
			cout << (j == 1 ? "" : " ");
			if (k && q.front() == j) {
				cout << 1; 
				q.pop();
			} else
				cout << 0;
		}
		cout << endl;
	}
}

/* vim: set ts=4 noet: */
