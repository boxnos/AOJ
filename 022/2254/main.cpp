#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

const auto gcu = getchar_unlocked;
const auto pcu = putchar_unlocked;
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template <typename T>
#define _HT template <typename H,typename... T>
_T _DEF(T,in,int c){T n=0;int m=1;while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_DEF(int, in){return in<int>(gcu());}
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
_T _SCAN(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_DEF(bool, scan, char &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_SCAN(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#endif
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);}
_OUT(const char *s){while(*s)pcu(*s++);}
_OUT(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_OUT(string s){for(char c:s)pcu(c);}
#endif
_T _OUT(T n){static char b[20];char *p=b,m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=n%10*m+'0',n/=10;while(p!=b)pcu(*--p);}
_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _OUT(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _OUT(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _OUTL(T&&... t){out(move(t)...);outl();}

struct range{
	int _e, _b = 0, _s = 1;
	range(int b, int e, int s): _e(e), _b(b), _s(s) {}
	range(int b, int e): _e(e), _b(b) {}
	range(int e) : _e(e) {}
	struct it {
		int _v, _s;
		it (int v, int s) : _v(v), _s(s) {}
		operator int () const {return _v;}
		operator int& () {return _v;}
		int operator* () const {return _v;}
		it& operator++ () {_v+=_s;return *this;}
	};
	it begin() {return {_b, _s};}
	it end() {return {_e, _s};}
};

using V = vector<int>;

int main() {
	for (int N; (N = in());) {
		vector<V> w(N, V(N + 1)), c(1 << N, V(N, INT_MAX));
		V b(1 << N);
		range r{N};
		for (auto &i: w)
			for (auto &j: i)
				j = in();
		for (int i: r)
			c[0][i] = w[i][0];
		for (int i: range(1, c.size())) {
			int m = i & ~-i, n = __builtin_ctz(i);
			for (int j = 0; j < N; j++)
				c[i][j] = min(c[m][j], w[j][n + 1]);
		}
		for (int i: range(b.size() - 2, -1, -1)) {
			b[i] = INT_MAX;
			for (int j: r)
				if (!((i >> j) & 1))
					b[i] = min(b[i], b[i + (1 << j)] + c[i][j]);
		}
		outl(b[0]);
	}
}

/* vim: set ts=4 noet: */
