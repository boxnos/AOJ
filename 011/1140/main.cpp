#include <cstdio>
#include <utility>
#include <cctype>
#include <vector>
#include <complex>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>
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
#define _I inline
#define _OP(t) _I operator t()
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
#define dbg(...) fprintf(stderr,__VA_ARGS__)
struct range{
	int e,b=0,s=1;range(int b,int e,int s):e(e),b(b),s(s){} range(int b,int e): e(e), b(b){} range(int e):e(e){}
	struct it{int v,s; it(int v,int s):v(v),s(s){} operator int()const{return v;} _I operator int&(){return v;}int operator*()const{return v;}
		_I it& operator++(){v+=s;return *this;} }; it begin(){return {b,s};} it end(){return {e,s};}};
#define times(i,n) for(int i=n;i;i--)

_T using V = vector<T>;
using P = complex<int>;
using PP = pair<P, int>;
int x(P a) {return real(a);};
int y(P a) {return imag(a);};
template <typename T, typename U> T x(pair<T, U> a) {return a.first;};
template <typename T, typename U> U y(pair<T, U> a) {return a.second;};
namespace std {
	bool operator < (P a, P b) {
		return x(a) == x(b) ? y(a) < y(b) : x(a) < x(b);
	}
}

int main() {
	for (P s; s = {in, in}, x(s);) {
		V<V<char>> m(y(s) + 2, V<char>(x(s) + 2, 'x'));
		map<P, int> d;
		int k {};
		for (int i: range(1, y(s) + 1)) {
			for (int j: range(1, x(s) + 1)) {
				int c {gcu()};
				m[i][j] = c;
				if (c == 'o') {
					m[i][j] = '*';
					d[{j, i}] = 0;
				} else if (c == '*')
					d[{j, i}] = ++k;
			}
			gcu();
		}
		int inf {INT_MAX / 2}, n = d.size();
		V<V<int>> di(n, V<int>(n, inf)), dp(1 << n, V<int>(n, inf));
		if (![&] {
			int b {};
			for (PP i: d) {
				if (b == n - 1)
					return true;
				int c {++b};
				V<V<bool>> v(y(s) + 2, V<bool>(x(s) + 2));
				queue<PP> q;
				q.push({x(i), 0});
				v[y(x(i))][x(x(i))] = true;
				if (![&] {
					do {
						PP a = q.front();
						q.pop();
						P u {x(a)};
						if (y(a) && m[y(u)][x(u)] == '*' && di[y(i)][d[u]] == inf) {
							di[y(i)][d[u]] = y(a);
							di[d[u]][y(i)] = y(a);
							if (++c == n)
								return true;
						}
						P d {1, 0};
						do {
							P t = u + d;
							if (!v[y(t)][x(t)] && m[y(t)][x(t)] != 'x') {
								v[y(t)][x(t)] = true;
								q.push({t ,y(a) + 1});
							}
						} while ((d *= P{0, 1}) != P{1, 0});
					} while (!q.empty());
					return false;
					}())
					return false;
			}
			return true;
		}()) {
			outl(-1);
			continue;
		}
		range rn(n);
		int N = 1 << n;
		for (int i: rn)
			dp[1 << i][0] = 0;
		for (int S: range(1, N)) {
			for (int v: rn)
				if (S & (1 << v))
					for (int u: rn)
						dp[S | (1 << u)][u] = min(dp[S | (1 << u)][u], dp[S][v] + di[v][u]);
		}
		outl(dp[N - 1][min_element(begin(dp[N - 1]), end(dp[N - 1])) - begin(dp[N - 1])]);
	}
}

/* vim: set ts=4 noet: */
