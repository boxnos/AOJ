#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define gcu getchar_unlocked
#define ii inline int in
#define bs inline bool scan
ii(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;}
ii() {return in(gcu());}
bs(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
bs(char &c){c=gcu();gcu();return c!=EOF;}
// bs(string &s){int c; s = "";
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#undef ii
#undef bs
#define pcu putchar_unlocked
#define vo inline void out
template <typename T>
vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
vo(const char *s){while(*s)pcu(*s++);}
vo(char c){pcu(c);}
// vo(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
vo(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T>
//vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef vo

typedef vector<int> v;

int main() {
	v d(5);
	for (;;) {
		for (int &n: d)
			if (!scan(n))
				return 0;
		sort(d.begin(), d.end());
		v h(5);
		h[0] = 1;
		int t = d[0], c = 0;
		for (auto i = d.begin() + 1; i != d.end(); i++) {
			if (t != *i) {
				if (t + 1 == *i)
					h[4]++;
				t = *i, h[0]++, c = 0;
			} else
				h[c]--, c++, h[c]++;
		}
		if (d == v{1, 10, 11, 12, 13})
			h[4]++;

		if (h[4] == 4) out("straight");
		else if (h[3]) out("four card");
		else if (h[1] && h[2]) out("full house");
		else if (h[2]) out("three card");
		else if (h[1] == 2) out("two pair");
		else if (h[1]) out("one pair");
		else out("null");
		out('\n');
	}
}

/* vim: set ts=4 noet: */
