#include <iostream>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <vector>
#include <unordered_map>
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

struct BMH {
	vector<int> d1;
	string T, P;
	int n, m;

	BMH() {
		scan(T);
		scan(P);
		n = T.size();
		m = P.size();

		d1 = vector<int>(256, m);
		for (int i = 0; i < m - 1; i++)
			d1[P[i]] = m - 1 - i;
	}

	int f(char c) {
		return d1[c];
	}

	/*
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
	*/

	void matcher() {
		for (int i = m - 1; i < n;) {
			int k = m - 1;
			for (; k >= 0 && P[k] == T[i]; i-- , k--);
			if (k < 0) {
				out(i + 1, '\n');
				i += m + 1;
			} else {
				i += max(d1[T[i]], m - k);
			}
		}

	}
	void print() {
		for (int x : d1)
			if (x != m)
				cerr << x << " ";
		cerr << endl;
	}
};

int main() {
	BMH bmh = BMH();
	bmh.matcher();
	//bmh.print();
}

/* vim: set ts=4 noet: */
