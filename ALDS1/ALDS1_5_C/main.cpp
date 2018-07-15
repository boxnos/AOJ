#include <cstdio>
#include <cmath>
#include <complex>
using namespace std;

typedef complex<double> P;

void pp(P x) { printf("%.8f %.8f\n", x.real(), x.imag()); }

void koch(int n, P b, P e)
{
	if (n-- == 0) {
		pp(b);
		return;
	}

	P p = (2.0 * b + e) / 3.0;
	P v[] = {b, p, p + (p - b) * P(cos(M_PI/3), sin(M_PI/3)), 2.0 * p - b, e};

	for (int i = 0; i < 4; i++)
		koch(n, v[i], v[i + 1]);
}

int main()
{
	int n;
	scanf("%d", &n);

	P b = {0, 0}, e = {100, 0};
	koch(n, b, e);
	pp(e);
}

/* vim: set ts=4 noet: */
