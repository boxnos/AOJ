#include <cstdio>
#include <utility>
#include <vector>
#include <complex>
using namespace std;

#define gcu getchar_unlocked
int in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;}
int in() {return in(gcu());}
bool scan(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
bool scan(char &c){c=gcu();gcu();return c!=EOF;}
bool scan(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#define pcu putchar_unlocked
#define vo inline void out
template <typename T>
vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
vo(const char *s){while(*s)pcu(*s++);}
vo(char c){pcu(c);}
vo(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail> vo(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T> vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef vo

typedef complex<double> P;

double cross(P a, P b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

bool convex(vector<P> &v) {
	vector<bool> res(4);
	for (int i = 0; i < 4; i++)
		res[i] = cross(v[i] - v[(i + 1) % 4], v[(i + 1) % 4] - v[(i + 2) % 4]) <= 0;
	for (int i = 0; i < 3; i++)
		if (res[i] != res[i + 1])
			return false;
	return true;
}

int main() {
	int i = 0;
	vector<P> vp(4);
	for (double x, y; scanf("%lf,%lf,", &x, &y) != EOF;) {
		vp[i++] = P(x, y);
		if (i == 4){
			out(convex(vp) ? "YES" : "NO", '\n');
			i = 0;
		}
	}
}

/* vim: set ts=4 noet: */
