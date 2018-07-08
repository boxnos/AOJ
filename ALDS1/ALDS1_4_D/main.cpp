#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n, K, min = 0, max = 0, P;
	scanf("%d %d", &n, &K);
	vector<int> w(n);
	for (int &x: w) {
		scanf("%d", &x);
		min = min > x ? min : x;
		max += x;
	}
	min--;
	
	for (;;) {
		P = (max + min) / 2;
		auto i = w.begin(), e = w.end(), last = e - 1;
		int k = 0, p = 0;
		for (; i != e && k < K; i++) {
			int tmp = p + *i;
			if (tmp > P) {
				p = *i, k++;
				if (i == last)
					k++;
			} else if (tmp == P)
				p = 0, k++;
			else {
				if (i == last) k++;
				p = tmp;
			}
		}
		if (i == e && k <= K)
			max = P;
		else
			min = P;

		if (max == min + 1) {
			P = max;
			break;
		}
	}
	printf("%d\n", P);
}

/* vim: set ts=4 noet: */
