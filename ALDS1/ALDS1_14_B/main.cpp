#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef unordered_map<char, int> sigma;
typedef vector<vector<int>> delta;

struct finite_automaton {
	sigma s;
	delta d;
	string T, P;

	finite_automaton() {
		cin >> T >> P;
		int i = 0;
		for (char c: P)
			if (!s.count(c))
				s[c] = i++;
		d = delta(P.size() + 1, vector<int>(s.size()));
		transition();
	}

	bool cmp(int k, int q, char a) {
		string pq = P.substr(0, q) + a;
		return P.substr(0, k) == pq.substr(pq.size() - k, k);
	}

	void transition() {
		for (size_t q = 0; q < d.size(); q++)
			for (auto a: s) {
				int k = min(d.size(), q + 2);
				do {
					k--;
				} while (!cmp(k, q, a.first));
				d[q][a.second] = k;
			}
	}

	void matcher() {
		size_t q = 0;
		for (size_t i = 0; i < T.size(); i++) {
			if (s.count(T[i]))
				q = d[q][s[T[i]]];
			else
				q = 0;
			if (q == P.size())
				cout << i - P.size() + 1 << endl;
		}
	}

	void print() {
		size_t k = 0;
		for (auto i: d) {
			cerr << (k < P.size() ? P[k++] : ' ');
			for (int j: i)
				cerr << " " << j;
			cerr << endl;
		}
	}
};

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	finite_automaton fa = finite_automaton();

	fa.matcher();
	//fa.print();
}

/* vim: set ts=4 noet: */
