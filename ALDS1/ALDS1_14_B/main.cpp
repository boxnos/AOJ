#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct KMP {
	vector<int> pi;
	string T, P;

	KMP() {
		cin >> T >> P;
		prifix_function();
	}

	void prifix_function() {
		pi.resize(P.size());
		int k = -1;
		pi[0] = k;
		for (size_t q = 1; q < P.size(); q++) {
			while (k >= 0 && P[k + 1] != P[q])
				k = pi[k];
			if (P[k + 1] == P[q])
				k++;
			pi[q] = k;
		}
	}

	void matcher() {
		int q = -1;
		int m = P.size();
		for (size_t i = 0; i < T.size(); i++) {
			while (q >= 0 && P[q + 1] != T[i])
				q = pi[q];
			if (P[q + 1] == T[i])
				q++;
			if (q == m - 1) {
				cout << i - m + 1 << endl;
				q = pi[q];
			}
		}
	}
	void print() {
		for (char c: P)
			cerr << "  " << c << " ";
		cerr << endl;
		for (int i: pi)
			cerr << setw(3) << i << " ";
		cerr << endl;
	}
};

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	KMP kmp = KMP();

	kmp.matcher();
	//kmp.print();
}

/* vim: set ts=4 noet: */
