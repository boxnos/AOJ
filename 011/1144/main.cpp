#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_T T in(int c){T n=0;bool m=false;while(isspace(c)){c=gcu();}if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m?-n:n;}
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

using v = vector<int>;
using vv = vector<v>;

constexpr int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct boad {
	vv b;
	int sx, sy, c = 1;
	boad(int w, int h) {
		b = vv(h, v(w));
		for (auto &y: b)
			for (int &x: y) {
				x = in();
				if (x == 2) {
					x = 0;
					sx = &x - &y[0];
					sy = &y - &b[0];
				}
			}
	}

	void dump() {
		outl("{", sx, ",", sy ,"}");
		for (auto y: b) {
			for (int x: y)
				out(x);
			outl();
		}
	}

};

int bfs (int w, int h) {
	queue<boad> q;
	q.push(boad(w, h));
	while (!q.empty()) {
		boad t = q.front();
		q.pop();
		for (int r = 0; r < 4; r++) {
			for (int i = 0, tx = t.sx, ty = t.sy;; i++) {
				tx += d[r][0]; ty += d[r][1];
				if(tx < 0 || tx >= w || ty < 0 || ty >= h)
					break;
				if (t.b[ty][tx] == 3)
					return t.c;
				else if (t.b[ty][tx] == 1) {
					if (t.c < 10 && i) {
						boad tt = t;
						tt.b[ty][tx] = 0;
						tt.sx = tx - d[r][0];
						tt.sy = ty - d[r][1];
						tt.c++;
						q.push(tt);
					}
					break;
				}
			}
		}
	}
	return -1;
}

int main() {
	for (int w, h; w = in(), h = in();)
		outl(bfs(w, h));
}

/* vim: set ts=4 noet: */
