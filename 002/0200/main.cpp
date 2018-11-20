#include <cstdio>
#include <utility>
#include <vector>
#include <array>
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

typedef vector<array<int, 2>> node;

int main() {
	for (int n, m; n = in(), m = in(), n || m;) {
		vector<node> v(m + 1, node(m + 1, {INT_MAX/2, INT_MAX/2}));
		while (n--) {
			int a = in(), b = in(), c = in(), t = in();
			v[a][b] = {c, t};
			v[b][a] = {c, t};
		}
		for (int k = 1; k <= m; k++)
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= m; j++) {
					auto &t = v[i][j];
					t[0] = min(t[0], v[i][k][0] + v[k][j][0]);
					t[1] = min(t[1], v[i][k][1] + v[k][j][1]);
				}
			}
		for (int k = in(); k--;) {
			int p = in(), q = in(), r = in();
			out(v[p][q][r], '\n');
		}
	}
}

/* vim: set ts=4 noet: */
