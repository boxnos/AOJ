#include <cstdio>
#include <utility>
#include <vector>
#include <array>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

#define gcu getchar_unlocked
int in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;}
int in() {return in(gcu());}
bool scan(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
bool scan(char &c){c=gcu();gcu();return c!=EOF;}
//bool scan(string &s){int c;s="";
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
template <typename head, typename... tail>
bool scan(head &h, tail&&... t){return scan(h) && scan(t...);}
#define pcu putchar_unlocked
#define vo inline void out
template <typename T>
vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
vo(const char *s){while(*s)pcu(*s++);}
vo(char c){pcu(c);}
//vo(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail> vo(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T> vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef vo

typedef unordered_map<int ,array<int, 2>> node;
struct cost {
	int n, c;
	bool operator <(const cost &co) const {
		return c > co.c;
	}
};

int main() {
	for (int n, m; n = in(), m = in(), n || m;) {
		vector<node> v(m + 1);
		while (n--) {
			int a, b, c, t;
			scan(a, b, c, t);
			v[a][b] = {c, t};
			v[b][a] = {c, t};
		}
		for (int k = in(); k--;) {
			vector<cost> w(m + 1, {0, INT_MAX});
			priority_queue<cost> Q;
			Q.push({in(), 0});
			int q = in(), r = in();
			while (!Q.empty()) {
				cost c = Q.top();
				Q.pop();
				if (c.n == q) {
					out(c.c, '\n');
					break;
				}
				if (w[c.n].n)
					continue;
				w[c.n].n = 1;
				for (auto x: v[c.n]) {
					int &m = w[x.first].c;
					m = min(m, c.c + x.second[r]);
					Q.push({x.first, m});
				}
			}
		}
	}
}

/* vim: set ts=4 noet: */
