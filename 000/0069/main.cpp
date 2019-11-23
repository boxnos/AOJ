#include <cstdio>
#include <utility>
#include <cctype>
#include <vector>
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

int main() {
	for (int n; (n = in);) {
		int m {(int) in - 1}, s {(int) in - 1}, d {in};
		V<V<bool>> a(d, V<bool>(n + 1)), memo = a;
		auto move = [&] (int x, int y) {
			return a[y][x] ? x - 1 : a[y][x + 1] ? x + 1 : x;
		};
		auto is_start = [&] (int x, int y) {
			for (int i: range(y, -1, -1)) {
				if (memo[i][x])
					return false;
				memo[i][x] = true;
				x = move(x, i);
			}
			return x == m;
		};
		auto add = [&] (int x, int y) {
			return !a[y][x - 1] && !a[y][x] && !a[y][x + 1];
		};

		for (auto &i: a) {
			for (int j: range(1, n))
				i[j] = gcu() - '0';
			gcu();
		}
		V<int> v(d);
		int c {s};
		for (int i: range(d - 1, -1, -1)) {
			v[i] = c;
			c = move(c, i);
		}
		if (c == m)
			outl(0);
		else
			[&] {
				for (int y: range(d)) {
					int x {v[y]};
					if (x > 0 && add(x, y) && is_start(x - 1, y - 1)) {
						outl(y + 1, ' ', x);
						return;
					} else if ((x < n - 1 && add(x + 1, y) && is_start(x + 1, y - 1))) {
						outl(y + 1, ' ', x + 1);
						return;
					}
				}
				outl(1);
			}();
	}
}

/* vim: set ts=4 noet: */
