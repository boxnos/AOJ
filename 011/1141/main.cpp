#include <cstdio>
#include <utility>
#include <vector>
#include <cmath>
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

vector<bool> sieve;

void make_sieve(int m) {
	sieve = vector<bool>(m, true);
	sieve[1] = false;
	for (int i = 3, e = sqrt(m); i <= e; i += 2) {
		if (!sieve[i])
			continue;
		for (int j = i * i; j < m; j += i)
			sieve[j] = false;
	}
}

bool is_prime(int n) {
	return (n % 2) ? sieve[n] : n == 2 ? true: false;
}

int main() {
	make_sieve(1000000);
	for (int a, b, c; a = in(), b = in(), c = in();) {
		for (int i = 0;; a += b) {
			if (is_prime(a)) {
				i++;
				if (i == c)
					break;
			}
		}
		out(a, '\n');
	}
}

/* vim: set ts=4 noet: */
