#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <deque>
using namespace std;

#define gcu getchar_unlocked
int in() {
	int n = 0, c = gcu();
	// bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	return n; }
	// return minus ? -n : n; }
void scan(string &s) {for (char c; !isspace(c = gcu()); s += c);}
#define pcu putchar_unlocked
template <typename T>
void out(T n) {
	static char buf[20];
	char *p = buf;
	//if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
void out(const char *s){while(*s)pcu(*s++);}
void out(char c){pcu(c);}
void out(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
void out(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

#define v vector
typedef v<string> vs;

struct rect_search {
	
	vs T, P;
	int H, W, R, C;

	struct node {char c; int n;};
	typedef deque<node> dn;
	v<dn> G;
	v<v<dn>> M;

	static void read(int &r, int &c, vs &S) {
		r = in();
		c = in();
		S = vs(r);
		for (auto &s: S)
			scan(s);
	}

	rect_search() {
		read(H, W, T);
		read(R, C, P);

		G = v<dn>(R);
		for (int i = 0; i < R; i++)
			G[i] = pack(P[i]);
		M = v<v<dn>>(H, v<dn>(W, dn(0)));
	}

	static dn pack(string s) {
		dn n;
		n.push_back({s[0], 1});

		for (size_t i = 1, j = 0; i < s.size(); i++)
			if (s[i] == n[j].c)
				n[j].n++;
			else {
				n.push_back({s[i], 1});
				j++;
			}
		return n;
	}

	bool cmp(int r, int c, dn &b) {
		if (M[r][c].size())
			return M[r][c] == b;
		dn a;
		if (c == 0)
			a = pack(T[r].substr(c, C));
		else {
			if (!M[r][c - 1].size())
				cmp(r, c - 1, b);
			a = M[r][c - 1];
			node n = a.front();
			a.pop_front();
			if (--n.n)
				a.push_front(n);
			if (a.size() && a.back().c == T[r][c + C - 1])
				a.back().n++;
			else
				a.push_back({T[r][c + C - 1], 1});
		}
		M[r][c] = a;
		return a == b;
	}

	void search () {
		for (int i = 0; i <= H - R; i++) {
			for (int j = 0; j <= W - C; j++) {
				int k = 0;
				for (; k < R; k++)
					if (!cmp(i + k, j, G[k]))
						break;
				if (k == R)
					out(i, ' ', j, '\n');
			}
		}
	}

	void debug(dn d) {
		for (auto n: d)
			out(n.c, "[", n.n ,"] ");
		out('\n');
	}
	void print() {
		for (auto r: T)
			out(r, '\n');
		for (auto r: P)
			out(r, '\n');
		for (auto r: G) {
			for (auto n: r)
				out(n.c, "[", n.n ,"] ");
			out('\n');
		}
	}
};

bool operator == (const rect_search::node &a, const rect_search::node &b) {
	return a.c == b.c && a.n == b.n;
}

int main() {
	rect_search rs = rect_search();
	//rs.print();
	rs.search();
}

/* vim: set ts=4 noet: */
