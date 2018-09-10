#include <iostream>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int n = 0, c = gcu();
	// bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	return n; }
	// return minus ? -n : n; }
si void scan(string &s) {for (char c; !isspace(c = gcu()); s += c);}
#define pcu putchar_unlocked
#define svo si void out
template <typename T>
svo(T n) {
	static char buf[20];
	char *p = buf;
	//if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
svo(char c){pcu(c);}
svo(string &s){for (char c: s) pcu(c);}
//template <typename T>
//svo(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
//svo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}
#undef svo
#undef si

struct KMP {
	vector<int> pi;
	string T, P;

	KMP() {
		scan(T);
		scan(P);
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
				out(i - m + 1, '\n');
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
