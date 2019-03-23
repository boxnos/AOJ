#include <cstdio>
#include <cctype>
#include <utility>
#include <array>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_T T in(int c){T n=0;bool m=false;while(isspace(c)){c=gcu();}if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
_in() {return in<int>(gcu());}
_T T scan(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_sc(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#endif
_HT _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _vo _il void out
#define _vl _il void outl
_vo(bool b) {pcu('0'+b);}
_vo(const char *s){while(*s)pcu(*s++);}
_vo(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_vo(string s){for(char c:s)pcu(c);}
#endif
_T _vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
_vl(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _vo(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

using T = array<array<int, 4>, 2>;
using N = pair<int, T>;

int find(T &t) {
	static const T e = {0, 1, 2, 3, 4, 5, 6, 7};
	static const int r[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	set<T> m;
	queue<N> q;
	q.push({0, t});
	m.insert(t);
	while (!q.empty()) {
		N a = q.front();
		q.pop();
		T &u = a.second;
		if (u == e)
			return a.first;
		int px = 0, py = 0;
		for (;; py++) {
			auto r = find(u[py].begin(), u[py].end(), 0);
			if (r != u[py].end()) {
				px = r - u[py].begin();
				break;
			}
		}
		for (auto &p: r) {
			int tx = px + p[0], ty = py + p[1];
			if (tx >= 0 && tx < 4 && ty >= 0 && ty < 2) {
				swap(u[py][px], u[ty][tx]);
				if (!m.count(u)) {
					m.insert(u);
					q.push({a.first + 1, u});
				}
				swap(u[py][px], u[ty][tx]);
			}
		}
	}
	return -1;
}

int main() {
	T t;
	for (;;) {
		for (auto &a: t)
			for (int &x: a)
				if (!scan(x))
					return 0;
		outl(find(t));
	}
}

/* vim: set ts=4 noet: */
