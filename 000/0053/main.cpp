#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
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

vector<int> sum = {2};

void make_sum(int m) {
	const int l = m / 2 + 1;
	vector<bool> s(l, true);
	for (int i = 3, e = sqrt(m); i <= e; i += 2) {
		if (!s[i / 2])
			continue;
		for (int j = i * i / 2; j < l; j += i)
			s[j] = false;
	}
	for (int i = 1, a = 2; i < l; i++)
		if (s[i]) {
			a += i * 2 + 1;
			sum.push_back(a);
		}
}

int main() {
	make_sum(104750);
	for (int n; (n = in());)
		out(sum[n - 1], '\n');
}

/* vim: set ts=4 noet: */
