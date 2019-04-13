#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
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
#define _vo _il void out
#define _vl _il void outl
_vo(bool b) {pcu('0'+b);}
_vo(const char *s){while(*s)pcu(*s++);}
_vo(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_vo(string s){for(char c:s)pcu(c);}
#endif
_T _vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
_vl(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _vo(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

vector<bool> sieve;
vector<int> primes;

void make_primes(int n) {
	sieve = vector<bool>(n, true);
	sieve[1] = false;
	for (int i = 4; i < n; i += 2)
		sieve[i] = false;
	for (int i = 9; i < n; i += 6)
		sieve[i] = false;
	for (int i = 6, e = sqrt(n); i <= e; i += 6) {
		for (int j : {i - 1, i + 1})
			if (sieve[j])
				for (int k = j * j; k < n; k += j)
					sieve[k] = false;
	}
	primes = {2, 3};
	for (int i = 6 ; i < n; i += 6)
		for (int j : {i - 1, i + 1})
			if (sieve[j])
				primes.push_back(j);
}

struct min_list {
	int max_size, size = 0;
	multiset<int> s;
	min_list(int s) {
		max_size = s;
	}
	bool insert(int n) {
		if (size < max_size) {
			s.insert(n);
			size++;
			return true;
		}
		auto r = max_element(s.begin(), s.end());
		if (n <= *r) {
			s.erase(r);
			s.insert(n);
			return true;
		} else
			return false;
	}
	int max() {
		return s.empty() ? INT_MAX : *s.rbegin();
	}
};

int main() {
	make_primes(110000);
	for (int n, p; n = in(), p = in(), n != -1;) {
		auto s = upper_bound(primes.begin(), primes.end(), n);
		min_list l(p);
		for (auto i = s; l.insert(*i + *i); i++)
			for (auto j = i + 1; l.insert(*i + *j) ;j++)
				;
		outl(l.max());
	}
}

/* vim: set ts=4 noet: */
