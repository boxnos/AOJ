#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

#define gcu getchar_unlocked
#define ii inline int in
#define is inline bool scan
ii(int c) {
	int n = 0;
	bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	//return n; }
	return minus ? -n : n; }
ii() {return in(gcu());}
is(int &n) {int c=gcu();return c==EOF?false:(n=in(c),true);}
is(char &c){c=gcu();gcu();return c!=EOF;}
//is(string &s) {int c;for(;;){c=gcu();if(c=='\n'||c==' ')return true;s+=c;}}
#undef ii
#define pcu putchar_unlocked
template <typename T>
void out(T n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
void out(const char *s){while(*s)pcu(*s++);}
void out(char c){pcu(c);}
//void out(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
void out(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

int main() {
	int gems;
	while ((gems = in())) {
		vector<vector<int>> map(21, vector<int>(21));
		for (int i = 0; i < gems; i++) {
			int x = in(), y = in();
			map[y][x] = true;
		}
		int operations = in();
		int x = 10, y = 10;
		while (operations--) {
			char d = gcu(); gcu();
			int n = in();
			int dx, dy;
			switch (d) {
			case 'N' : dx = 0, dy =  1; break;
			case 'E' : dx = 1, dy =  0; break;
			case 'S' : dx = 0, dy = -1; break;
			default  : dx = -1, dy = 0; break;
			}
			for (int i = n; i > 0; i--) {
				x += dx; y += dy;
				if (map[y][x]) {
					map[y][x] = false;
					gems--;
				}
			}
		}
		out(gems ? "No" : "Yes", '\n');
	}
}

/* vim: set ts=4 noet: */
