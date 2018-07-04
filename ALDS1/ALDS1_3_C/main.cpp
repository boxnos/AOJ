#include <cstdio>
#include <list>
using namespace std;

int main()
{
	int n, k;
	char s[15];
	list<int> l;

	scanf("%d", &n);

	while (n--) {
		scanf("%s", s);
		if (*s == 'i') {
			scanf("%d", &k);
			l.push_front(k);
			continue;
		}
		switch (*(s + 6)) {
		case 'F':
			l.pop_front();
			break;
		case 'L':
			l.pop_back();
			break;
		default:
			scanf("%d", &k);
			for (auto i = l.begin(), e = l.end(); i != e; i++)
				if (*i == k) {
					l.erase(i);
					break;
				}
		}
	}

	int &f = l.front();
	for (int &x: l)
		printf("%s%d", (&f == &x ? "" : " "), x);
	printf("\n");
}

/* vim: set ts=4 noet: */
