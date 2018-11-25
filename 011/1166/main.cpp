#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define gcu getchar_unlocked
int in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
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

struct node {int x, y, d;};
typedef vector<bool> vb;

int main() {
	for (int w, h; w = in(), h = in(), w || h;) {
		vector<vb> m(h * 2 + 1, vb(w + 2));
		for (size_t i = 1; i < m.size() - 1; i++)
			for (int j = 1, e = i % 2 ? (gcu(), w - 1) : w; j < e + 1; j++)
				m[i][j] = !in();
		vector<vb> v(h + 1, vb(w + 1));
		queue<node> q;
		q.push({1, 1, 1});
		int r = 0;
		while (!q.empty()) {
			node n = q.front();
			q.pop();
			if (n.x == w && n.y == h)
				r = n.d;
			if (v[n.y][n.x])
				continue;
			v[n.y][n.x] = true;
			static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1},
					   tx[] = {0, 0, -1, 0}, ty[] = {-1, 0, -1, -2};
			for (int i = 0; i < 4; i++)
				if (m[n.y * 2 + ty[i]][n.x + tx[i]] && !v[n.y + dy[i]][n.x + dx[i]])
					q.push({n.x + dx[i], n.y + dy[i], n.d + 1});
		}
		out(r, '\n');
	}
}

/* vim: set ts=4 noet: */
