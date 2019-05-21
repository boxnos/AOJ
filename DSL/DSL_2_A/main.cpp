#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

const auto gcu = getchar_unlocked;
const auto pcu = putchar_unlocked;
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_T T in(int c){T n=0;int m=1;while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_in() {return in<int>(gcu());}
_T T scan(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_sc(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#endif
_HT _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _ot _il void out
#define _ol _il void outl
_ot(bool b) {pcu('0'+b);}
_ot(const char *s){while(*s)pcu(*s++);}
_ot(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_ot(string s){for(char c:s)pcu(c);}
#endif
_T _ot(T n){static char buf[20];char *p=buf;if(n<0)pcu('-'),n*=-1;
	if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10; while (p!=buf)pcu(*--p);}
_ol(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _ot(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _ot(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _ol(T&&... t){out(move(t)...);outl();}

struct RMQ {
	int n;
	vector<int> t;
	RMQ (int l) :
		n(1 << (32 - __builtin_clz(l - 1))),
		t(n * 2 - 1, INT_MAX) {}
	void update(int i, int v) {
		i += n - 1, t[i] = v;
		while (i) {
			i = (i - 1) / 2;
			t[i] = min(t[i * 2 + 1], t[i * 2 + 2]);
		}
	}
	int find(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)
			return INT_MAX;
		if (a <= l && r <= b)
			return t[k];
		int m = (l + r) / 2;
		k *= 2;
		return min(find(a, b, k + 1, l, m),
				   find(a, b, k + 2, m, r));
	}
};

int main() {
	RMQ r(in());
	for (int q = in(); q; q--) {
		if (in()) {
			int x = in(), y = in();
			outl(r.find(x, y + 1, 0, 0, r.n));
		} else {
			int x = in(), y = in();
			r.update(x, y);
		}
	}
}

/* vim: set ts=4 noet: */
