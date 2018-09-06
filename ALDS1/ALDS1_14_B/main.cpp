#include <iostream>
#include <string>
using namespace std;

void rk(string &T, string &P, int d, int q) {
	int n = T.size(), m = P.size();
	int p = 0, t = 0, h = 1;

	for (int i = 0; i < m - 1; i++)
		h = h * d % q;

	for (int i = 0; i < m; i++) {
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}

	for (int s = 0; s <= n - m; s++) {
		if (p == t && P == T.substr(s, m))
			cout << s << endl;
		if (s < n - m)
			t =  ((t - T[s] * h) * d + T[s + m]) % q;
		if (t < 0)
            t = (t + q);
	}
}

int main() {
	string t, p;
	cin >> t >> p;

	if (t.size() >= p.size())
		rk(t, p, 256, 26339);
}

/* vim: set ts=4 noet: */
