#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> v;
typedef v::iterator vi;
int c = 0;

void ms(vi l, vi r)
{
	if (l + 1 < r) {
		int d = r - l;
		vi m = l + d / 2;
		c += d;
		ms(l, m);
		ms(m, r);
		inplace_merge(l, m, r);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	v S(n);
	for (int &x :S)
		scanf("%d", &x);

	ms(S.begin(), S.end());

	for (int &x: S)
		printf("%s%d", &x == &S[0] ? "": " ", x);
	puts("");
	printf("%d\n", c);
}

/* vim: set ts=4 noet: */
