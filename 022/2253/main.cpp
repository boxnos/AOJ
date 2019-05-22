#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
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

struct map {
	struct node {int x, y, c;};
	int c;
	vector<vector<bool>> t;
	map(int i) : c(i), t(i * 2 + 1, vector<bool>(i * 2 + 1, true)) {}
	void put(int x, int y) {
		t[y][x] = false;
	}
	int walk(int x, int y, int c) {
		static const int tx[] = {1, 0, -1, -1, 0, 1}, ty[] = {0, -1, -1, 0, 1, 1};
		queue<node> q;
		q.push({x, y, c});
		int r = 0;
		while (!q.empty()) {
			node n = q.front();
			q.pop();
			if (!t[n.y][n.x])
				continue;
			put(n.x, n.y);
			r++;
			if (n.c--)
				for (int i = 0; i < 6; i++)
					if (t[n.y + ty[i]][n.x + tx[i]])
						q.push({n.x + tx[i], n.y + ty[i], n.c});
		}
		return r;
	}
};

int main() {
	for (int t, n; t = in(), n = in(), t || n;) {
		map m(30 + t);
		while (n--) {
			int x = in(), y = in();
			m.put(x + m.c, y + m.c);
		}
		int x = in(), y = in();
		outl(m.walk(x + m.c, y + m.c, t));
	}
}

/* vim: set ts=4 noet: */
