#include <cstdio>
#include <cctype>
#include <vector>
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

struct heap{
	v h = {0};

	void insert(int x) {
		h.push_back(x);
		int c = h.size() - 1;
		for (int p = c / 2; p; c = p, p /= 2)
			if (x > h[p])
				h[c] = h[p];
			else
				break;
		h[c] = x;
	}
	void extract() {
		out(h[1], '\n');
		h[1] = h.back();
		int v = h[1];
		h.pop_back();

		int p = 1, H = h.size();
		for (int c = 2; c < H; c = p *2) {
			if (c + 1 < H && h[c] < h[c + 1])
				c++;
			if (v > h[c])
				break;
			h[p] = h[c];
			p = c;
		}
		h[p] = v;
	}
};

int main() {
	char s[20];
	heap h;

	for (;;) {
		scan(s);
		switch(s[2]) {
		case 's':
			h.insert(in());
			continue;
		case 't':
			h.extract();
			continue;
		}
		break;
	}
}

/* vim: set ts=4 noet: */
