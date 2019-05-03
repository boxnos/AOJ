#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <string>
#include <functional>
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

using VV = vector<string>;
using P = pair<int, char>;

int main() {
	for (int w, h; w = in(), h = in();) {
		VV m(h);
		int B = 0, W = 0;
		for (auto &y: m)
			scan(y);
		function<P(int, int)> f = [&](int x, int y) {
			char &t = m[y][x];
			if (t == 'B' || t == 'W')
				return P{0, t};
			t = 'x';
			int rx = 1, ry = 0;
			P r = {1, 'N'};
			for (int i = 0; i < 4; i++) {
				int nx = x + rx, ny = y + ry;
				if (nx >= 0 && ny >= 0 && nx < w && ny < h && m[ny][nx] != 'x') {
					P x = f(nx, ny);
					r.first += x.first;
					r.second = x.second == 'C' ? 'C' :
						x.second + r.second == 'W' + 'B' ? 'C' :
						r.second == 'N' ? x.second : r.second;
				}
				swap(rx, ry *= -1);
			}
			return r;
		};
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (m[i][j] == '.') {
					P r = f(j, i);
					if (r.second == 'B')
						B += r.first;
					else if (r.second == 'W')
						W += r.first;
				}
		outl(B, ' ', W);
	}
}

/* vim: set ts=4 noet: */
