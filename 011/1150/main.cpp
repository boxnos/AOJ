#include <cstdio>
#include <utility>
#include <cctype>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

#ifdef __linux
#define _U(s) s##_unlocked
#else
#define _U(s) _##s##_nolock
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
#define gcu _U(getchar)
#define pcu _U(putchar)
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template <typename T>
#define _HT template <typename H,typename... T>
#define _OP(t) inline operator t()
struct _in {
#ifdef _GLIBCXX_STRING
	_OP(string){string s;char c;while(isspace(c = gcu()));do{s+=c;}while(c=gcu(),c!=' '&&c!='\n'&&c!=EOF);return s;}
#define _S
#endif
	_OP(char){char c=gcu();gcu();return c;}
	_OP(double){double d; scanf("%lf",&d); gcu();return d;}
	_T _OP(T){T n{},m{1},c;while(isspace(c = gcu()));if(c=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
} in;
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
#ifdef _S
_SCAN(string &o) {int c{gcu()};if(c==EOF)return false;else{ungetc(c,stdin);string t=move(in);o=t;return true;}}
#endif
_T _SCAN(T &o) {int c{gcu()};return c==EOF?false:(ungetc(c,stdin),o=in,true);}
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);}
_OUT(const char *s){while(*s)pcu(*s++);}
_OUT(char c){pcu(c);}
#ifdef _S
_OUT(string &s){for(char c:s)pcu(c);}
#endif
_T _OUT(T n){static char b[20];char *p=b;T m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
	_T _OUT(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
_HT _OUT(H &&h, T... t){out(h);out(t...);}
template <typename... T> _OUTL(T... t){out(t...);outl();}
#define dbg(...) fprintf(stderr,__VA_ARGS__);
struct range{
	int e,b=0,s=1;range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
	struct it{int v,s; it(int _v,int _s):v(_v),s(_s){} operator int()const{return v;} operator int&(){return v;}int operator*()const{return v;}
		it& operator++(){v+=s;return *this;} }; it begin(){return {b,s};} it end(){return {e,s};}};
#define times(i,n) for(int i=n;i;i--)

_T using V = vector<T>;

struct P {
	int x, y, c, l;
	bool operator < (P a) const {
		return c > a.c;
	}
};

int main() {
	for (int w, h; w = in, h = in;) {
		enum {S = 10, T, M = INT_MAX};
		V<V<int>> s(h + 6, V<int>(w + 6, M));
		range rw(3, w + 3), rh(3, h + 3);
		for (int i: rh)
			for (int j: rw) {
				char t = in;
				s[i][j] = isdigit(t) ? t - '0' : t == 'T' ? 0 : t == 'S' ? S : T;
			}
		int m {M};
		for (int i: rw)
			if (s[h + 2][i] == S) {
				for (int l: {1, -1})
					m = min(m, [&] {
						priority_queue<P> q;
						V<V<V<bool>>> v(h + 6, V<V<bool>>(w + 6, V<bool>(2)));
						q.push({i, h + 2, 0, l});
						while (!q.empty()) {
							P t {q.top()};
							q.pop();
							int vi {t.l == 1 ? 0 : 1};
							if (!s[t.y][t.x])
								return t.c;
							if (v[t.y][t.x][vi])
								continue;
							v[t.y][t.x][vi] = true;
							for (int dy: range(-2, 3))
								for (int dx {1}; dx <= 3 - abs(dy); dx++) {
									int x {t.x + dx * t.l}, y {t.y + dy * t.l};
									if (!v[y][x][!vi] && s[y][x] < 10)
										q.push({x, y, t.c + s[y][x], t.l * -1});
								}
						}
						return static_cast<int>(M);
					}());
				}
		outl(m == M ? -1 : m);
	}
}

/* vim: set ts=4 noet: */
