#include <cstdio>
#include <cmath>
#include <deque>
using namespace std;

struct D {double x; double y;};
typedef deque<D> v;

void koch(int n, v &d)
{
	if (n-- == 0)
		return;

	D e = d.back(); d.pop_back();
	D b = d.back();
	D p = {e.x - b.x, e.y - b.y};
	double l = sqrt(p.x * p.x + p.y * p.y);
	double r = atan2(p.y, p.x);
	auto f = [&](D x) {d.push_back(x); koch(n, d);};

	f({p.x / 3 + b.x, p.y / 3 + b.y});
	f({l / 3 * cos(M_PI / 3 + r) + p.x / 3 + b.x, l / 3 * sin(M_PI / 3 + r) + p.y / 3 + b.y});
	f({p.x * 2 / 3 + b.x, p.y * 2 / 3 + b.y});
	f(e);
}

int main()
{
	int n;
	v d = {{0, 0}, {100, 0}};
	scanf("%d", &n);

	koch(n, d);
	
	for (D x : d)
		printf("%.8f %.8f\n", x.x, x.y);
}

/* vim: set ts=4 noet: */
