#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int n = 0, c = gcu();
	// bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	return n; }
	// return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
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
svo(const char *s){while(*s)pcu(*s++);}
svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
//svo(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
svo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}
#undef svo
#undef si

int main()
{
	int n = in();
	vector<int> W(n), S;
	vector<bool> V(n);
	unordered_map<int, int> M;
	for (int &w: W)
		w = in();
	S = W;
	sort(S.begin(), S.end());
	for (int i = 0; i < n; i++)
		M[S[i]] = i;
	int r = 0, s = S[0];
	for (int i = 0; i < n; i++) {
		if (V[i])
			continue;
		int S = 0, l = 0, m = INT_MAX;
		for (int c = i, v; !V[c]; c = M[v]) {
			V[c] = true;
			v = W[c];
			S += v;
			l++;
			m = min(m, v);
		}
		r += min(S + (l - 2) * m, m + S + (l + 1) * s);
	}
	out(r, '\n');
}

/* vim: set ts=4 noet: */
