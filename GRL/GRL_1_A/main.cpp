#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

const auto gcu = getchar_unlocked;
const auto pcu = putchar_unlocked;
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _sc _il bool scan
_T T in(int c){T n=0;int m=1;while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_il int in() {return in<int>(gcu());}
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
_T _ot(T n){static char b[20];char *p=b,m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=n%10*m+'0',n/=10;while(p!=b)pcu(*--p);}
_ol(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _ot(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _ot(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _ol(T&&... t){out(move(t)...);outl();}

struct graph {
	struct node {
		int n, w;
		bool operator < (const node a) const {return w > a.w;}
	};
	using V = vector<node>;
	vector<V> nodes;

	graph(int v) : nodes(v) {}
	V dks(int r) {
		V w(nodes.size(), {0, INT_MAX});
		w[r].w = 0;
		priority_queue<node> q;
		q.push({r, 0});
		while (!q.empty()) {
			node n = q.top();
			q.pop();
			for (node &x: nodes[n.n]) {
				w[x.n].w = min(w[x.n].w, n.w + x.w);
				if (!w[n.n].n)
					q.push({x.n, w[x.n].w});
			}
			w[n.n].n |= 1;
		}
		return w;
	}
};

int main() {
	graph g(in());
	int E = in(), r = in();
	for (int i = E; i; i--) {
		int s = in();
		g.nodes[s].push_back({in(), in()});
	}
	for (auto n: g.dks(r))
		if (n.w == INT_MAX)
			outl("INF");
		else
			outl(n.w);
}

/* vim: set ts=4 noet: */
