#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
using namespace std;

const auto gcu = getchar_unlocked;
const auto pcu = putchar_unlocked;
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

struct weighted_union_find {
	struct node {int p, r, w;};
	struct P {int p, w;};
	vector<node> nodes;
	weighted_union_find (int n) : nodes(n) {
		for (node &n: nodes)
			n.p = &n - &nodes[0];
	}
	P find(int x) {
		node &n = nodes[x];
		if (n.p != x) {
			P p = find(n.p);
			n.p = p.p;
			n.w = p.w += n.w;
			return p;
		} else
			return {x, 0};
	}
	void unite(int a, int b, int w) {
		P ar = find(a), br = find(b);
		node &an = nodes[ar.p], &bn = nodes[br.p];
		w = w + ar.w - br.w;
		if (an.r > bn.r) {
			bn.p = ar.p;
			bn.w = w;
		} else {
			an.p = br.p;
			an.w = -w;
			if (an.r == bn.r)
				bn.r++;
		}
	}
	void diff(int a, int b) {
		P ar = find(a), br = find(b);
		if (ar.p == br.p)
			outl(find(b).w - find(a).w);
		else
			outl("?");
	}
};

int main() {
	weighted_union_find u(in());
	for (int q = in(); q; q--) {
		if (in()) {
			int x = in();
			u.diff(x, in());
		} else {
			int x = in(), y = in();
			u.unite(x, y, in());
		}
	}
}

/* vim: set ts=4 noet: */
