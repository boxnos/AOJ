#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
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
_T _OUT(vector<T> v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
_HT _OUT(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _OUTL(T&&... t){out(move(t)...);outl();}
struct range{
	int e,b=0,s=1; range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
	struct it { int v, s; it (int _v, int _s) : v(_v), s(_s) {} operator int()const{return v;} operator int&(){return v;} int operator*()const{return v;}
		it& operator++(){v+=s;return *this;} }; it begin() {return {b, s};} it end() {return {e, s};}};

template <typename T>
using V = vector<T>;
using P = pair<int, int>;
inline int x(P o) {return o.first;}
inline int y(P o) {return o.second;}
P operator +(P a, P b) {return {x(a) + x(b), y(a) + y(b)};}
struct hash_p {
	size_t operator()(const P &p) const {return (x(p) << 16) + y(p);}
};
using N = unordered_map<int, unordered_set<P, hash_p>>;

int main() {
	for (int h, w, c; h = in() + 2, w = in() + 2, c = in();) {
		V<V<int>> p(h, V<int>(w));
		V<V<bool>> v(h, V<bool>(w));
		N n;
		const V<P> rot {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		for (int y: range(1, h - 1))
			for (int x: range(1, w - 1))
				p[y][x] = in();
		for (int i: range(1, max(h, w) - 1)) {
			if (i < h)
				v[i][0] = v[i][w - 1] = true;
			if (i < w)
				v[0][i] = v[h - 1][i] = true;
		}
		function<void(P, int, N &)> expand = [&](P a, int c, N &n) {
			n[c].insert(a);
			for (P i: rot) {
				P t{a + i};
				if (!v[y(t)][x(t)] && c == p[y(t)][x(t)] && !n[c].count(t))
					expand(t, c, n);
			}};
		function<int(int, int, int, N)> dfs = [&](int i, int r, int tc, N n) {
			auto l = n[tc];
			for (auto p: l) {
				v[y(p)][x(p)] = true;
				r++;
			}
			n.erase(tc);
			for (auto j: l)
				for (P k: rot) {
					P t{j + k};
					if (!v[y(t)][x(t)])
						expand(t, p[y(t)][x(t)], n);
				}
			if (i == 5)
				r += (int) n[c].size();
			else if (!n.empty()) {
				int tr = r;
				for (auto j: n)
					r = max(r, dfs(i + 1, tr, j.first,n));
			}
			for (auto p: l)
				v[y(p)][x(p)] = false;
			return r;
		};
		int tc = p[1][1];
		expand({1, 1}, tc, n);
		outl(dfs(1, 0, tc, n));
	}
}

/* vim: set ts=4 noet: */
