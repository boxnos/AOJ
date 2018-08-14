#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true; else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
#define pcu putchar_unlocked
#define svo si void out
template <typename T>
svo(T n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
svo(const char *s){while(*s)pcu(*s++);}
svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
svo(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
//svo(vector<T> &v){for(int &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}

typedef vector<int> v;

void make_heap(v &h) {
	const int H = h.size();
	for (int i = H / 2; i > 0; i--) {
		int v = h[i], p = i;
		for (int c = p * 2; c < H; c = p * 2) {
			if (c + 1 < H && h[c] < h[c + 1])
				++c;
			if (v > h[c])
				break;
			h[p] = h[c];
			p = c;
		}
		h[p] = v;
	}
}

int main() {
	int n = in();
	v h(n + 1);
	auto e = h.end();
	for_each(h.begin() + 1, h.end(), [](int &x){x = in();});
	make_heap(h);
	for_each(h.begin() + 1, h.end(), [](int x){out(' ', x);});
	out('\n');
}

/* vim: set ts=4 noet: */
