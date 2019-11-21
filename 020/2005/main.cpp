#include <cstdio>
#include <utility>
#include <cctype>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
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
struct range{
	int e,b=0,s=1;range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
	struct it{int v,s; it(int _v,int _s):v(_v),s(_s){} operator int()const{return v;} operator int&(){return v;}int operator*()const{return v;}
		it& operator++(){v+=s;return *this;} }; it begin(){return {b,s};} it end(){return {e,s};}};
#define times(i,n) for(int i=n;i;i--)

template <typename T>
using V = vector<T>;

struct N {
	int n, c;
	bool operator < (N a) const {
		return c > a.c;
	}
};

int main() {
	for (int n, m, s, g1, g2; n = in, m = in, s = in, g1 = in, g2 = in;) {
		s--, g1--, g2--;
		V<V<N>> g(n), h(n);
		times(i, m) {
			int s {(int) in - 1}, e {(int) in - 1}, c {in};
			g[s].push_back({e, c});
			h[e].push_back({s, c});
		}
		auto f = [&](int s, V<V<N>> &x) {
			V<int> d(n, INT_MAX / 4);
			d[s] = 0;
			priority_queue<N> q;
			q.push({s, 0});
			while (!q.empty()) {
				N t = q.top();
				q.pop();
				for (N i : x[t.n])
					if (d[i.n] > d[t.n] + i.c)
						q.push({i.n , d[i.n] = d[t.n] + i.c});
			}
			return d;
		};
		V<int> rs {f(s, g)}, r1 {f(g1, h)}, r2 {f(g2, h)};
		int r {INT_MAX};
		for (int i: range(n))
			r = min(r, rs[i] + r1[i] + r2[i]);
		outl(r);
	}
}

/* vim: set ts=4 noet: */
