#include <cstdio>
#include <utility>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define gcu getchar_unlocked
int in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;}
int in() {return in(gcu());}
bool scan(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
bool scan(char &c){c=gcu();gcu();return c!=EOF;}
//bool scan(string &s){int c;s="";
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#define pcu putchar_unlocked
#define vo inline void out
template <typename T>
vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
vo(const char *s){while(*s)pcu(*s++);}
vo(char c){pcu(c);}
vo(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail> vo(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T> vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef vo

struct point {int x, y;};
typedef vector<string> map;

int distance(point s, point e) {
	return abs(e.x - s.x) + abs(e.y - s.y);
}
struct node {
	int g, h, f;
	point p;
	bool operator < (const node &a) const {
		return f > a.f;
	};
};

int walk(point s, point e, map m) {
	priority_queue<node> q;
	static point d[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	int sd = distance(s, e);
	q.push({0, sd, sd, s});

	while (!q.empty()) {
		node n = q.top();
		q.pop();
		if (!n.h)
			return n.g;
		m[n.p.y][n.p.x] = '#';
		for (auto p: d) {
			p.x += n.p.x;
			p.y += n.p.y;
			if (p.x >= 0 && p.x < (int) m[0].size()
				&& p.y >= 0 && p.y < (int) m.size()) {
				char &c = m[p.y][p.x];
				if (c == '.') {
					int g = n.g + 1, h = distance(p, e);
					q.push({g, h, g + h, p});
				}
			}
		}
	}
	return 0;
}


int main() {
	int h = in(), w = in(), d = 0, n = in();
	vector<string> m(h);
	vector<point> p(n);
	point s;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c = gcu();
			if (isdigit(c)) {
				p[c - '0' - 1] = {j, i};
				c = '.';
			} else if (c == 'S') {
				s = {j, i};
				c = '.';
			}
			m[i].push_back(c);
		}
		gcu();
	}
	for (auto t: p) {
		d += walk(s, t, m);
		s = t;
	}
	out(d, '\n');
}

/* vim: set ts=4 noet: */
