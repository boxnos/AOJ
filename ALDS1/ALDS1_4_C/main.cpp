#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string s, t;
	unordered_set<string> d;

	while (n--) {
		cin >> s >> t;
		switch(s[0]) {
		case 'i':
			d.insert(t); break;
		case 'f':
			cout << (d.find(t) != d.end() ? "yes" : "no") << endl;
		}
	}
}

/*
#include <cstdio>
static inline int in()
{
    int c, n = 0;
    while ((c = getchar_unlocked()) >= '0' && c <= '9')
		// n = 10 * n + (c - '0');
		n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
*/


/* vim: set ts=4 noet: */
